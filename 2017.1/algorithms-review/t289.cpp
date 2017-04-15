#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  void gameOfLife(vector<vector<int>>& board) {
    if (board.size() == 0 || board[0].size() == 0)
      return;
    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++){
      for (int j = 0; j < m; j++){
        int count = 0;
        int left = max(0, j-1), right = min(m-1, j+1);
        int up = max(0, i-1), bottom = min(n-1, i+1);
        for (int jj = left; jj <= right; jj++){
          for (int ii = up; ii <= bottom; ii++){
            if (ii == i && jj == j)
              continue;
            count += (board[ii][jj] & 1);
          }
        }
        if (((board[i][j] & 1) == 0) && count == 3)
          board[i][j] |= 2;
        else if ((board[i][j] & 1) == 1) {
          if (count == 2 || count == 3)
            board[i][j] |= 2;
          else
            board[i][j] &= 1;
        }
      }
    }
    for (int i = 0; i < n; i ++)
      for (int j = 0; j < m; j++)
        board[i][j] >>= 1;
  }
};


int main(){
  vector<vector<int>> para2 = {{1, 0, 1, 1},
                              {0, 1, 1, 0},
                              {1, 0, 1, 0}};
  vector<vector<int>> para = {{1, 1}, {1, 0}};
  Solution sol;
  sol.gameOfLife(para);
  for (int i = 0; i < para.size(); i++){
    for (int j =0; j < para[i].size(); j++)
      cout << para[i][j] << " ";
    cout <<endl;
  }
  return 0;
}
