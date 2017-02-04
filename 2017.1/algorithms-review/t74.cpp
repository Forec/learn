#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  bool searchMatrix(vector<vector<int>> & matrix, int target){
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return false;
    int row = 0, col = matrix[0].size() -1;
    while ( row < matrix.size() && col >= 0){
      if (target < matrix[row][col])
        col--;
      else if (target > matrix[row][col])
        row++;
      else
        return true;
    }
    return false;
  }
};

int main(){
  vector<vector<int>> mat = {  {1,   3,  5,  7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 50}};
  Solution sol;
  cout << sol.searchMatrix(mat, 12) << endl;
  return 0;
}
