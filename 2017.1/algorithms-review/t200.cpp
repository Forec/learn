#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Solution {
private:
  array<int, 4> dx = {1, 0, 0, -1};
  array<int, 4> dy = {0, 1, -1, 0};
  int m, n;
  void dfs(vector<vector<char>> & grid, int x, int y){
    if (grid[x][y] == '0')
      return;
    grid[x][y] = '0';
    for (int i =0; i < 4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
        dfs(grid, nx, ny);
      }
    }
  }
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0 || grid[0].size() == 0)
      return 0;
    m = grid.size(); n = grid[0].size();
    int res = 0;
    for (int i =0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (grid[i][j] == '1'){
          dfs(grid, i, j);
          res++;
        }
      }
    }
    return res;
  }
};

int main(){
  vector<vector<char>> map = {{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};
  Solution sol;
  cout << sol.numIslands(map) << endl;
  return 0;
}
