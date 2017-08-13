#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return ans;
    int m = matrix.size(), n = matrix[0].size();
    int minmn = min(m, n);
    for (int boarder = 0; boarder < minmn / 2 + (minmn&1); boarder ++ ){
      // boarder, boarder -> boarder, n - boarder -1 -> m - boarder -1, n - boarder -1 -> m-boarder-1, boarder -> boarder -> boarder
      for (int i = boarder; i < n - boarder; i++)
        ans.push_back(matrix[boarder][i]);
      for (int i = boarder + 1; i < m - boarder; i++)
        ans.push_back(matrix[i][n - boarder - 1]);
      if (m-boarder-1 == boarder)
        continue;
      for (int i = n - boarder - 2; i >= boarder ; i--)
        ans.push_back(matrix[m-boarder-1][i]);
      if (n-boarder-1 == boarder)
        continue;
      for (int i = m - boarder - 2; i > boarder ; i--)
        ans.push_back(matrix[i][boarder]);
    }
    return ans;
  }
};

int main(){
  vector<vector<int>> mat = {{1, 2, 3},
                             {4, 5, 6},
                             {7, 8, 9}};
  vector<vector<int>> mat2 = {{1, 2, 3, 4, 5, 6, 7},
                              {8, 9, 10, 11, 12, 13, 14},
                              {15, 16, 17, 18, 19, 20, 21}};
  vector<vector<int>> mat3 = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9},
                              {10, 11, 12},
                              {13, 14, 15},
                              {16, 17, 18},
                              {19, 20, 21}};
  vector<vector<int>> mat4 = {{1}};
  Solution sol;
  vector<int> ans = sol.spiralOrder(mat4);
  for (int i = 0; i <ans.size(); i++){
    cout << ans[i] << endl;
  }
  return 0;
}
