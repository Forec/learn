#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> res;
    queue<int> S;
    vector<int> degree(numCourses, 0);
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < numCourses; i++)
      dict[i] = vector<int>();
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
      degree[it->first]++;
      dict[it->second].push_back(it->first);
    }
    for (int i =0 ; i < numCourses; i++){
      if (degree[i] == 0){
        S.push(i);
      }
    }
    while (!S.empty()){
      int now = S.front();
      res.push_back(now);
      S.pop();
      for (int i = 0; i < dict[now].size(); i ++){
        if (--degree[dict[now][i]] == 0)
          S.push(dict[now][i]);
      }
    }
    for (int i =0; i < numCourses; i++){
      if (degree[i] != 0)
        return vector<int>();
    }
    return res;
  }
};


int main(){
  vector<pair<int, int>> para = {pair<int, int>(1, 0)};
  vector<pair<int, int>> para2 = {pair<int, int>(1, 0), pair<int, int>(3, 1), pair<int, int>(2, 0), pair<int, int>(3, 2)};
  Solution sol;
  vector<int> ans = sol.findOrder(4, para2);
  for (int i =0 ;i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
