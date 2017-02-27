#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, -1, 1, 0};
  int m, n, len;
  vector<vector<char>> _board;
  vector<vector<bool>> _used;
  string _word;
  bool valid(int x, int y){
    if (x >= 0 && y >= 0 && x < m && y < n && !_used[x][y])
      return true;
    return false;
  }
  bool dfs(int x, int y, int pos){
    if (pos == len)
      return true;
    char cur = _word[pos];
    _used[x][y] = true;
    for (int i = 0; i < 4; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if (!valid(nx, ny))
        continue;
      if (_board[nx][ny] != cur)
        continue;
      if (dfs(nx, ny, pos+1))
        return true;
    }
    _used[x][y] = false;
    return false;
  }
public:
  bool exist(vector<vector<char>>& board, string word) {
    _board = board;
    _word = word;
    m = board.size();
    if (word.length() == 0)
      return true;
    if (m == 0 || board[0].size() == 0)
      return false;
    n = board[0].size();
    _used.resize(m, vector<bool>(n, false));
    len = word.length();
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (_board[i][j] == _word[0]){
          if (dfs(i, j, 1))
            return true;
        }
      }
    }
    return false;
  }
};

int main(){
  vector<vector<char>> board = {
                                {'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}
  };
  Solution sol;
  cout << sol.exist(board, "ABCCED") << endl;
  Solution sol1;
  cout << sol1.exist(board, "SEE") << endl;
  Solution sol2;
  cout << sol2.exist(board, "ABCB") << endl;
  return 0;
}
