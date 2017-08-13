#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
//#include <bitset>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
private:
  void dfs(int &ans, vector<bool> &flag_col, vector<bool> &flag_45, vector<bool> &flag_135, int row, const int &n){
    if (row == n){
      ans ++;
      return;
    }
    for (int col = 0; col < n; col++){
      if (flag_col[col] && flag_45[col+row] && flag_135[n-1+row-col]){
        flag_col[col] = flag_45[col+row] = flag_135[n-1+row-col] = false;
        dfs(ans, flag_col, flag_45, flag_135, row+1, n);
        flag_col[col] = flag_45[col+row] = flag_135[n-1+row-col] = true;
      }
    }
  }
public:
  int totalNQueens(int n) {
    vector<bool> flag_col(n, true);
    vector<bool> flag_45(2*n-1, true);
    vector<bool> flag_135(2*n-1, true);
    int ans = 0;
    dfs(ans, flag_col, flag_45, flag_135, 0, n);
    return ans;
  }
};

int main(){
  Solution sol;
  int ans = sol.totalNQueens(8);
  cout << ans << endl;
  return 0;
}
