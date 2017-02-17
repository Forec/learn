#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    int boarder = 0;
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++){
      int size = n - 2 * boarder - 1;
      for (int j = boarder; j < boarder + size; j++){
        vector<vector<int>> pos= {{boarder, j},
                                  {j, n - boarder - 1},
                                  {n - boarder - 1, n - j -1},
                                  {n - j - 1, boarder}};
        int tmp = matrix[boarder][j];
        for (int k = 1; k <= 4; k++){
          int curPos = k % 4;
          //          cout << pos[curPos][0] << " " << pos[curPos][1] << "||" ;
          int tk = matrix[pos[curPos][0]][pos[curPos][1]];
          matrix[pos[curPos][0]][pos[curPos][1]] = tmp;
          tmp = tk;
        }
        //    cout <<endl;
      }
      boarder++;
    }
  }
};

int main(){
  vector<vector<int>> para = {{1, 2, 3, 4},
                              {5, 6, 7, 8},
                              {9, 10, 11, 12},
                              {13, 14, 15, 16}};
  Solution sol;
  sol.rotate(para);
  for (int i = 0; i < para.size(); i++){
    for (int j =0; j < para[i].size(); j++){
      cout << para[i][j] << " ";
    }
    cout <<endl;
  }
  return 0;
}
