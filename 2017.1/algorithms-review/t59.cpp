#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int p = 1;
    for (int boarder = 0; boarder < n / 2 + (n & 1); boarder++) {
      for (int i = boarder; i < n - boarder; i++)
        ans[boarder][i] = p++;
      for (int i = boarder + 1; i < n - boarder; i++)
        ans[i][n - boarder - 1] = p++;
      if (n - boarder - 1 == boarder)
        continue;
      for (int i = n - boarder - 2; i >= boarder; i--)
        ans[n - boarder - 1][i] = p++;
      if (n - boarder - 1 == boarder)
        continue;
      for (int i = n - boarder - 2; i > boarder; i--)
        ans[i][boarder] = p++;
    }
    return ans;
  }
};

int main() {
  Solution sol;
  vector<vector<int>> ans = sol.generateMatrix(2);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
