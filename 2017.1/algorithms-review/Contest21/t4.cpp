#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
private:
  int m, n;
  bool valid(int x, int y){
    if (x >= 0 && x < m && y >= 0 && y < n)
      return true;
    return false;
  }
public:
  vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    int x = click[0], y = click[1];
    if (board.size() == 0 || board[0].size() == 0)
      return board;
    m = board.size();
    n = board[0].size();
    if (board[x][y] == 'M'){
      board[x][y] = 'X';
      return board;
    }
    vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dy = {-1, 0, 1, 1, -1, 0, 1, -1};
    if (board[x][y] == 'E'){
      int findBomb = 0;
      for (int i = 0 ; i < 8; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (!valid(nx, ny))
          continue;
        if (board[nx][ny] == 'M'){
          findBomb++;
        }
      }
      if (findBomb == 0){
        board[x][y] = 'B';
        for (int i = 0; i < 8; i++){
          int nx = x + dx[i], ny = y + dy[i];
          if (!valid(nx, ny))
            continue;
          if (board[nx][ny] == 'E'){
            vector<int> tmp = {nx, ny};
            updateBoard(board, tmp);
          }
        }
      } else {
        board[x][y] = '0' + findBomb;
      }
    }
    return board;
  }
};

int main(){
  Solution sol;
  vector<vector<char>> para = {{'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'M', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'},
                               {'E', 'E', 'E', 'E', 'E'}};
  vector<vector<char>> para2 = {{'B', '1', 'E', '1', 'B'},
                                {'B', '1', 'M', '1', 'B'},
                                {'B', '1', '1', '1', 'B'},
                                {'B', 'B', 'B', 'B', 'B'}};
  vector<int> point1 = {3, 0};
  vector<int> point2 = {1, 2};
  vector<vector<char>> ans = sol.updateBoard(para2, point2);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
