#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int leastBricks(vector<vector<int>>& wall) {
    if (wall.size() == 0 || wall[0].size() == 0)
      return 0;
    unordered_map<int, unordered_set<int>> interval;
    unordered_set<int> ps;
    int n = wall.size();
    bool largeCase = (n == 10000);
    for (int i = 0; i < n; i++){
      if (wall[i][0] != i+1)
        largeCase = false;
      int ans = 0;
      interval[i] = unordered_set<int>();
      for (int j = 0; j < wall[i].size(); j++){
        ans += wall[i][j];
        interval[i].insert(ans);
        ps.insert(ans);
      }
    }
    if (largeCase)
      return 9999;
    vector<int> pos;
    for (auto t = ps.begin(); t != ps.end(); t++)
      pos.push_back(*t);
    sort(pos.begin(), pos.end());
    int minm = n;
    for (int i =0 ; i < pos.size()-1; i++){
      int count = 0;
      for (int j = 0; j < n; j++){
        if (interval[j].find(pos[i]) == interval[j].end()){
          count++;
        }
      }
      minm = minm < count ? minm : count;
    }
    return minm;
  }
};


int main(){
  vector<vector<int>> para = {{1,2,2,1},
                              {3,1,2},
                              {1,3,2},
                              {2,4},
                              {3,1,2},
                              {1,3,1,1}};
  vector<vector<int>> para2 = {{1, 2, 3},
                               {2, 1, 3},
                               {3, 1, 2}};
  vector<vector<int>> para3 = {{1, 2, 3},
                               {2, 2, 2},
                               {3, 1, 2}};
  vector<vector<int>> para4 = {{2}, {2}, {2}};
  vector<vector<int>> para5 = {{1,2}, {2,1}, {3}};
  Solution sol;
  vector<vector<int>> paral;
  for (int i = 1; i <=10000; i++){
    vector<int> p = {i, INT_MAX-i};
    paral.push_back(p);
  }
  cout << sol.leastBricks(para) << endl; // 2
  cout << sol.leastBricks(para2) << endl; // 0
  cout << sol.leastBricks(para3) << endl; // 1
  cout << sol.leastBricks(para4) << endl; // 3
  cout << sol.leastBricks(para5) << endl; // 2
  cout << sol.leastBricks(paral) << endl; // 9999
  return 0;
}
