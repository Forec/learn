#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
  void solve(vector<vector<string>>&res, vector<string>&queens, vector<int> & flag_col,
             vector<int> &flag_45, vector<int> &flag_135, int row, const int& n){
    if (row == n){
      res.push_back(queens);
      return;
    }
    for (int col = 0; col < n; col++){
      if (flag_col[col] && flag_45[row+col] && flag_135[n-1+col-row]){
        flag_col[col] = flag_45[row+col] = flag_135[n-1+col-row] = 0;
        queens[row][col]='Q';
        solve(res, queens, flag_col, flag_45, flag_135, row + 1, n);
        queens[row][col] = '.';
        flag_col[col] = flag_45[row+col] = flag_135[n-1+col-row] = 1;
      }
    }
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> queens(n, string(n, '.'));
    vector<int> flag_col(n, 1), flag_45(2*n-1, 1), flag_135(2*n-1,1);
    solve(ans, queens, flag_col, flag_45, flag_135, 0, n);
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
