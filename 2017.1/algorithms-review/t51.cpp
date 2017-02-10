#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
  void solve(vector<vector<string>> & res,vector<string> &queens, int row, const int &n){
    if (row == n){
      res.push_back(queens);
      return;
    }
    for (int col = 0; col < n; col++){
      if (isValid(queens, row, col, n)){
        queens[row][col] = 'Q';
        solve(res, queens, row+1, n);
        queens[row][col] = '.';
      }
    }
  }
  bool isValid(vector<string> &queens, int row, int col, const int &n){
    for (int i = 0; i < row; ++i){
      if (queens[i][col] == 'Q')
        return false;
    }
    for (int i = row - 1, j = col -1; i>= 0 && j>=0; i--,j--){
      if (queens[i][j] =='Q')
        return false;
    }
    for (int i = row -1, j =col+1; i >= 0 && j < n; i--, j++){
      if (queens[i][j] =='Q')
        return false;
    }
    return true;
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> queens(n, string(n, '.'));
    solve(ans, queens, 0, n);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<vector<string>> ans = sol.solveNQueens(8);
  cout << ans.size() << endl;
  // for (int i = 0; i < ans.size(); i++){
  //   for (int j = 0; j < ans[i].size(); j++){
  //     cout << ans[i][j] << endl;
  //   }
  //   cout << endl;
  // }
  return 0;
}
