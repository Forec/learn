#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return;
    int column0 = 1;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; i++){
      if (matrix[i][0] == 0)
        column0 = 0;
      for (int j = 1; j < n; j++){
        if (matrix[i][j] == 0){
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }
    for (int i = m - 1; i >= 0; i --){
      for (int j = n - 1; j >= 1; j--){
        if (!matrix[i][0] || !matrix[0][j])
          matrix[i][j] = 0;
      }
      if (column0 == 0)
        matrix[i][0] = 0;
    }
  }
};

int main(){
  vector<vector<int>> para = {{0, 2, 1, 3},
                              {9, 0, 1, 2},
                              {3, 0, 2, 0},
                              {1, 2, 3, 4}};
  vector<vector<int>> para2 = {{1, 0}};
  Solution sol;
  sol.setZeroes(para2);
  for (int i = 0; i < para2.size(); i++){
    for (int j = 0; j < para2[i].size(); j++){
      cout <<  para2[i][j] << " " ;
    }
    cout << endl;
  }
  return 0;
}
