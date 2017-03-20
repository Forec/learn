#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y? x : y;
  }
public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    if (buildings.size() == 0){
      return vector<pair<int, int>>();
    }
    int i = 0, n = buildings.size();
    int currentPos, currentHeight;
    priority_queue<pair<int, int>> leftBuildings;
    vector<pair<int, int>> res;
    while (i < n || !leftBuildings.empty()){
      if (leftBuildings.empty() || i < n && buildings[i][0] <= leftBuildings.top().second){
        currentPos = buildings[i][0];
        while (i < n && buildings[i][0] == currentPos){
          leftBuildings.push(make_pair(buildings[i][2], buildings[i][1]));
          i++;
        }
      } else {
        currentPos = leftBuildings.top().second;
        while (!leftBuildings.empty() && leftBuildings.top().second <= currentPos){
          leftBuildings.pop();
        }
      }
      currentHeight = leftBuildings.empty() ? 0 : leftBuildings.top().first;
      if (res.empty() || (res.back().second != currentHeight))
        res.push_back(make_pair(currentPos, currentHeight));
    }
    return res;
  }
};

int main(){
  Solution sol;
  vector<vector<int>> para2 = {{1, 3, 1}, {2, 5, 2}, {2, 4, 3}};
  vector<vector<int>> para = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
  vector<pair<int, int>> ans = sol.getSkyline(para2);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
  return 0;
}
