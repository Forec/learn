#include <vector>
#include <utility>
#include "test/quickcheck.h"

using namespace std;

template <typename T>
class VECTOR2D {
private:
  vector<vector<T>> vec;
public:
  VECTOR2D(vector<vector<T>> & p){
    vec = p;
  }
  VECTOR2D() {
  }
  vector<vector<T>> getVec(){
    return vec;
  }
  void set(vector<vector<T>> &p){
    vec = p;
  }
  void push_back(vector<T> & last) {
    vec.push_back(last);
  }
  typename vector<vector<T>>::iterator getIterator() {
    return vec.begin();
  }
  void erase(typename vector<vector<T>>::iterator & it) {
    vec.erase(it);
  }
  vector<T> get(int i){
    return vec[i];
  }
  int size(){
    return vec.size();
  }
  friend ostream & operator << (ostream & os, const VECTOR2D& v){
    os << "[";
    for (int i = 0; i < v.vec.size(); i++){
      os << "[";
      if (v.vec[i].size() > 0){
        os << v.vec[i][0];
        for (int j = 1; j < v.vec[i].size(); j++){
          os << ", " << v.vec[i][j];
        }
      }
      os << "]";
      if (i < v.vec.size() - 1){
        os << ",\n    " ;
      }
    }
    return os;
  }
  bool operator == (const VECTOR2D & v){
    if (v.vec.size() != vec.size())
      return false;
    for (int i = 0; i < vec.size(); i++){
      if (v.vec[i].size() != vec[i].size())
        return false;
      for (int j = 0; j < vec[i].size(); j++)
        if (v.vec[i][j] != vec[i][j])
          return false;
    }
    return true;
  }
};

class Solution {
private:
  void dfs(int x, int y, vector<vector<char>> &board,int m, int n){
    if (board[x][y] != 'O')
      return;
    board[x][y] = 'E';
    if (x + 1 < m && board[x+1][y] == 'O')
      dfs(x+1, y, board, m, n);
    if (y + 1 < n && board[x][y+1] == 'O')
      dfs(x, y+1, board, m ,n);
    if (x > 1 && board[x-1][y] =='O')
      dfs(x-1, y, board, m, n);
    if (y > 1 && board[x][y-1] == 'O')
      dfs(x, y-1, board, m, n);
  }
public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m == 0)
      return;
    int n = board[0].size();
    for (int i = 0; i < m; i ++){
      if (board[i][0] == 'O'){
        dfs(i, 0, board, m, n);
      }
      if (n > 1 && board[i][n-1] == 'O'){
        dfs(i, n-1, board, m, n);
      }
    }
    for (int j = 0; j < n-1; j++){
      if (board[0][j] == 'O'){
        dfs(0, j, board, m, n);
      }
      if (m > 1 && board[m-1][j] == 'O'){
        dfs(m-1, j, board, m, n);
      }
    }
    for (int i =0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (board[i][j] == 'O')
          board[i][j] = 'X';
        if (board[i][j] == 'E')
          board[i][j] = 'O';
      }
    }
  }
  VECTOR2D<char> run(VECTOR2D<char>& in){
    vector<vector<char>> board = in.getVec();
    solve(board);
    return VECTOR2D<char>(board);
  }
};

int main(){
  Solution sol;
  vector<vector<vector<char>>> inputs = {{{'X', 'X', 'X', 'O'},
                                          {'X', 'O', 'O', 'X'},
                                          {'X', 'X', 'O', 'X'},
                                          {'X', 'O', 'X', 'X'}}};
  vector<vector<vector<char>>> outputs = {{{'X', 'X', 'X', 'O'},
                                            {'X', 'X', 'X', 'X'},
                                            {'X', 'X', 'X', 'X'},
                                            {'X', 'O', 'X', 'X'}}};
  vector<VECTOR2D<char>> in, out;
  for (int i = 0; i < inputs.size(); i++){
    in.push_back(VECTOR2D<char>(inputs[i]));
    out.push_back(VECTOR2D<char>(outputs[i]));
  }
  QuickCheck<VECTOR2D<char>, VECTOR2D<char>, Solution> *q = new QuickCheck<VECTOR2D<char>, VECTOR2D<char>, Solution>(in, out);
  q->runTests();
  return 0;
}
