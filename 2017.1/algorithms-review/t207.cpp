#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    queue<int> S;
    vector<int> degree(numCourses, 0);
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < numCourses; i++)
      dict[i] = vector<int>();
    for (auto it = prerequisites.begin(); it != prerequisites.end(); it++){
      degree[it->second]++;
      dict[it->first].push_back(it->second);
    }
    for (int i =0 ; i < numCourses; i++){
      if (degree[i] == 0){
        S.push(i);
      }
    }
    while (!S.empty()){
      int now = S.front();
      S.pop();
      for (int i = 0; i < dict[now].size(); i ++){
        if (--degree[dict[now][i]] == 0)
          S.push(dict[now][i]);
      }
    }
    for (int i =0; i < numCourses; i++){
      if (degree[i] != 0)
        return false;
    }
    return true;
  }
};


int main(){
  vector<pair<int, int>> para = {pair<int, int>(1, 0)};
  vector<pair<int, int>> para2 = {pair<int, int>(1, 0), pair<int, int>(0, 1)};
  Solution sol;
  cout << (sol.canFinish(2, para) == true) << endl;
  cout << (sol.canFinish(2, para2) == false) << endl;
  return 0;
}
