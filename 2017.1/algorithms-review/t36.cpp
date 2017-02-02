#include <iostream>
#include <vector>

using namespace std;

class Solution{
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

int main(){
	vector<vector<char>> map = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
								{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
								{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
								{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
								{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
								{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
								{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
								{'.', '.', '.', '4', '1', '9', '.', '2', '5'},
								{'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
	Solution sol;
	cout << sol.isValidSudoku(map) <<endl;
	return 0;
}
