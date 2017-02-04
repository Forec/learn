#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <utility>
#include <bitset>
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

class Solution{
private:
  struct cell{
    uint8_t value;
    uint8_t numPossibilities;
    bitset<10> constraints;
    cell(): value(0), numPossibilities(9), constraints(){};
  };
  array<array<cell, 9>, 9> cells;
  vector<pair<int, int>> bt;
  bool set(int i, int j, int v){
    cell & c = cells[i][j];
    if (c.value == v)      // Is this cell already have value v?
      return true;
    if (c.constraints[v])  // Is v invalid for this cell?
      return false;
    c.constraints = bitset<10>(0x3FE);
    c.constraints.reset(v);
    c.numPossibilities = 1;// The cell is determined without uncertainty.
    c.value = v;
    for (int k = 0; k < 9; k++){
      if (i != k && !updateConstraints(k, j, v))
        return false;
      if (j != k && !updateConstraints(i, k, v))
        return false;
      int ix = (i/3) * 3 + k /3;
      int jx = (j/3) * 3 + k %3;
      if (ix != i && jx != j && !updateConstraints(ix, jx, v))
        return false;
    }
    return true;
  }
  // update constraints of cells[i][j].
  bool updateConstraints(int i, int j, int excludeValue){
    cell& c = cells[i][j];
    if (c.constraints[excludeValue])
      return true;
    if (c.value == excludeValue)
      return false;
    c.constraints.set(excludeValue);
    if (--c.numPossibilities > 1)// still have some uncertainty.
      return true;
    for (int v = 1; v <= 9; v++){// find which number if valid and unique for this cell.
      if (!c.constraints[v])
        return set(i, j, v);
    }
    return false;
  }
  bool findValuesForEmptyCells(){
    bt.clear();
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (!cells[i][j].value)
          bt.push_back(make_pair(i, j));
    sort(bt.begin(), bt.end(), [this](const pair<int, int>& a, const pair<int, int>&b){
        return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities;
      });
    return backtrack(0);
  }
  bool backtrack(int k){
    if (k >= bt.size())
      return true;
    int i = bt[k].first, j = bt[k].second;
    if (cells[i][j].value)
      return backtrack(k+1);
    auto constraints = cells[i][j].constraints;
    array<array<cell, 9>, 9> snapshot(cells);
    for (int v = 1; v <= 9; v++){
      if (!constraints[v]){
        if (set(i, j, v)){
          if (backtrack(k+1))
            return true;
        }
        cells = snapshot; // trace back
      }
    }
    return false;
  }
public:
  void solveSudoku(vector<vector<char>> &board){
    cells = array<array<cell, 9>, 9>();
    for (int i = 0; i < 9; i++){
      for (int j = 0; j < 9; j++){
        if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
          return; // sudoku is either incorrect or unsolvable
      }
    }
    if (!findValuesForEmptyCells())
      return; // sudoku is unsolvable
    // copyback
    for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
        if (cells[i][j].value)
          board[i][j] = cells[i][j].value + '0';
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
