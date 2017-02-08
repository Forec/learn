#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return ans;
    int m = matrix.size(), n =  matrix[0].size();
    int total = m * n;
    ans.resize(total);
    ans[0] = matrix[0][0];
    int i = 1, row = 0, col = 0;
    while (i < total){
      while (i < total && row >= 1 && col < n - 1) // up-right
        ans[i++] = matrix[--row][++col];
      if (i < total && col < n - 1)
        ans[i++] = matrix[row][++col]; // right
      else if (i < total && row + 1 < m)
        ans[i++] = matrix[++row][col]; // down
      while ( i < total && row < m - 1 && col >= 1) // down-left
        ans[i++] = matrix[++row][--col];
      if (i < total && row < m - 1) // down
        ans[i++] = matrix[++row][col];
      else if (i < total && col < n - 1)//right
        ans[i++] = matrix[row][++col];
    }
    return ans;
  }
};

int main(){
  vector<vector<int>> map = { { 1, 2, 3 },
                              { 4, 5, 6 },
                              { 7, 8, 9 }};
  vector<vector<int>> map2 = {{1, 2},
                              {3, 4}};
  vector<vector<int>> map3 = {{1, 2, 3, 4, 5, 6, 7}};
  vector<vector<int>> map4 = {{1, 2, 3, 4, 5, 6},
                              {7, 8, 9, 10, 11, 12}};
  Solution sol;
  vector<int> ans = sol.findDiagonalOrder(map);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}
