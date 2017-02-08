#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if (obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0)
      return 0;
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> pre(n, 0);
    vector<int> cur(n, 0);
    int block = 1;
    if (obstacleGrid[0][0] == 1)
      return 0;
    for (int i = 0; i < n; i++){
      if (obstacleGrid[0][i] == 1)
        block = 0;
      pre[i] = block;
    }
    for (int j = 1; j < m; j++){
      if (obstacleGrid[j][0] == 1 || pre[0] == 0){
        cur[0] = 0;
        pre[0] = 0;
      } else {
        cur[0] = 1;
      }
      for (int i = 1; i < n; i++){
        if (obstacleGrid[j][i] == 0)
          cur[i] = cur[i-1] + pre[i];
        else
          cur[i] = 0;
        pre[i] = cur[i];
      }
    }
    return pre[n-1];
  }
};

int main(){
  Solution sol;
  vector<vector<int>> sin = {{0}};
  vector<vector<int>> map = {{0, 1, 0, 0, 0},
                             {1, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0}};
  cout << sol.uniquePathsWithObstacles(sin) << endl;
  return 0;
}
