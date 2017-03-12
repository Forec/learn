#include <iostream>
#include <vector>
using namespace std;

class Solution_UP_TO_DOWN {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.size() == 0 || dungeon[0].size() == 0)
      return 1;
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> f(m, vector<int>(n, 0));
    vector<vector<int>> g(m, vector<int>(n, 1));
    f[0][0] = dungeon[0][0] >= 0 ? 1 : 1-dungeon[0][0];
    g[0][0] = dungeon[0][0] >= 0 ? 1+dungeon[0][0] : 1;
    for (int i = 1; i < n; i++){
      if (g[0][i-1] + dungeon[0][i] > 0){
        g[0][i] = g[0][i-1] + dungeon[0][i];
        f[0][i] = f[0][i-1];
      }
      else{
        f[0][i] = f[0][i-1] + 1 - (g[0][i-1] + dungeon[0][i]);
        g[0][i] = 1;
      }
    }
    for (int i = 1; i < m; i++){
      if (g[i-1][0] + dungeon[i][0] > 0){
        f[i][0] = f[i-1][0];
        g[i][0] = g[i-1][0] + dungeon[i][0];
      }
      else{
        f[i][0] = f[0][i-1] + 1 - (g[i-1][0] + dungeon[i][0]);
        g[i][0] = 1;
      }
    }
    for (int i = 1; i < m; i++){
      for (int j = 1; j < n; j++){
        int upF = f[i-1][j], leftF = f[i][j-1];
        int upG = g[i-1][j] + dungeon[i][j], leftG = g[i][j-1] + dungeon[i][j];
        int minUp, minLeft;
        if (upG <= 0){
          upF += 1 - upG;
          upG = 1;
        }
        if (leftG <= 0){
          leftF += 1 - leftG;
          leftG = 1;
        }
        if (upF < leftF){
          f[i][j] = upF;
          g[i][j] = upG;
        } else {
          f[i][j] = leftF;
          g[i][j] = leftG;
        }
      }
    }
    for (int i = 0 ; i < m; i++){
      for (int j = 0; j < n;j++){
        cout << f[i][j] << " ";
      }
      cout << endl;
    }
    for (int i = 0 ; i < m; i++){
      for (int j = 0; j < n;j++){
        cout << g[i][j] << " ";
      }
      cout << endl;
    }
    return f[m-1][n-1];
  }
};

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    if (dungeon.size() == 0 || dungeon[0].size() == 0)
      return 1;
    int m = dungeon.size(), n = dungeon[0].size();
    vector<vector<int>> f(m, vector<int>(n, INT_MAX));
    f[m-1][n-1] = 1 - dungeon[m-1][n-1] <= 0 ? 1 : 1- dungeon[m-1][n-1];
    for (int i = m -1; i >= 0; i--){
      for (int j = n-1; j >= 0; j--){
        if (i < m-1){
          if (f[i][j] > f[i+1][j] - dungeon[i][j]){
            f[i][j] = f[i+1][j] - dungeon[i][j];
          }
        }
        if (j < n-1){
          if (f[i][j] > f[i][j+1] - dungeon[i][j]){
            f[i][j] = f[i][j+1] - dungeon[i][j];
          }
        }
        if (f[i][j] <= 0)
          f[i][j] = 1;
      }
    }
    for (int i = 0 ; i < m; i++){
      for (int j = 0; j < n;j++){
        cout << f[i][j] << " ";
      }
      cout << endl;
    }
    return f[0][0];
  }
};


int main(){
  Solution sol;
  vector<vector<int>> para ={{-2, -3, -3},
                             {-5, -10, 1},
                             {10, 30, -5}};
  vector<vector<int>> para2 = {{2,0,-1}};
  vector<vector<int>> para3 = {{1, -3, 3},
                               {0, -2, 0},
                               {-3, -3, -3}};
  cout << sol.calculateMinimumHP(para) << endl;
  return 0;
}
