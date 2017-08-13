#include <iostream>
#include <vector>
using namespace std;

class Solution2{
public:
	bool isValidSudoku(vector<vector<char>> & board){
		for (int i = 0; i < 9; i++){
			vector<int> used(10, 0);
			for (int j = 0; j < 9; j++){
				if (board[i][j] == '.')
					continue;
				if (used[board[i][j] - '0'] != 0)
					return false;
				used[board[i][j] - '0'] = 1;
			}
		}
		for (int i = 0; i < 9; i++){
			vector<int> used(10, 0);
			for (int j = 0; j < 9; j++){
				if (board[j][i] == '.')
					continue;
				if (used[board[j][i] - '0'] != 0)
					return false;
				used[board[j][i] - '0'] = 1;
			}
		}
		for (int i = 0; i < 9; i+= 3){
			for (int j = 0; j < 9; j+= 3){
				vector<int> used(10, 0);
				for (int l = i; l < i + 3; l++){
					for (int m = j; m < j + 3; m++){
						if (board[l][m] == '.')
							continue;
						if (used[board[l][m] - '0'] != 0)
							return false;
						used[board[l][m] - '0'] = 1;
					}
				}
			}
		}
		return true;
	}
};


class Solution {
private:
  bool isValid(vector<vector<char>> & board, int row, int col, char c){
    for (int i = 0; i < 9; i++){
      if (board[i][col] != '.' && board[i][col] == c) return false;
      if (board[row][i] != '.' && board[row][i] == c) return false;
      if (board[3*(row/3) + i/3][3*(col/3) + i%3] != '.' &&
          board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
  }
  bool solve(vector<vector<char>>& board){
    for (int i = 0; i < board.size(); i++){
      for (int j = 0; j < board[0].size(); j++){
        if (board[i][j] == '.'){
          for (char c = '1'; c <= '9'; c++){
            if (isValid(board, i, j, c)){
              board[i][j] = c;
              if (solve(board))
                return true;
              else
                board[i][j] = '.';
            }
          }
          return false;// each number from 1 to 9 cannot be assigned to this cell
        }
      }
    }
    return true;
  }
public:
  void solveSudoku(vector<vector<char>>& board) {
    if (board.size() == 0)
      return;
    solve(board);
  }
};

int main(){
  Solution sol;
  Solution2 check;
	vector<string> para2     = {"..9748...",
                              "7........",
                              ".2.1.9...",
                              "..7...24.",
                              ".64.1.59.",
                              ".98...3..",
                              "...8.3.2.",
                              "........6",
                              "...2759.."};
  vector<vector<char>> para(9, vector<char>(9, '.'));
  for (int i =0; i < para2.size(); i++){
    for (int j = 0; j < 9; j ++)
      para[i][j] = para2[i][j];
  }
  vector<vector<char>> map = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '2', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  sol.solveSudoku(para);
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++)
      cout << para[i][j] << " ";
    cout << endl;
  }
  cout << check.isValidSudoku(para) << endl;
  return 0;
}
