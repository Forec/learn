#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0)
      return 0;
    vector<vector<int>> dict(grid.size(), vector<int>(grid[0].size(), 0));
    int res = 0;
    for (int i = 0; i < grid.size(); i++){
      for (int j = 0; j < grid[0].size(); j++){
        if (i == 0 && j == 0)
          continue;
        if (i == 0)
          grid[0][j] += grid[0][j-1];
        else if (j == 0)
          grid[i][0] += grid[i-1][0];
        else
          grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
      }
    }
    return grid[grid.size()-1][grid[0].size()-1];
  }
};

int main(){
  Solution sol;
  vector<vector<int>> map = {{0, 1, 0, 0, 0},
                             {1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0}};
  cout << sol.minPathSum(map) << endl;
  return 0;
}
