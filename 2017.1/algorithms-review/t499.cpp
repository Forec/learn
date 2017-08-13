#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution{
private:
  string roll(vector<vector<int>> &maze, int ballRow, int ballCol, const vector<int> & hole, int dr, int dc, int dist, const string&path, pair<string, int>&res){
    if (dist < res.second){
      if (dr != 0 || dc != 0){
        while (ballRow + dr >= 0 && ballCol + dc >= 0 &&
               ballRow + dr < maze.size() && ballCol + dc < maze[0].size() &&
               maze[ballRow + dr][ballCol + dc] != 1){
          ballRow += dr;
          ballCol += dc;
          ++dist;
          if (ballRow == hole[0] && ballCol == hole[1] && dist < res.second)
            res = {path, dist};
        }
      }
      if (maze[ballRow][ballCol] == 0 || dist  + 2 < maze[ballRow][ballCol]){
        maze[ballRow][ballCol] = dist + 2;
        if (dr == 0) roll(maze, ballRow, ballCol, hole, 1, 0, dist, path + "d", res);
        if (dc == 0) roll(maze, ballRow, ballCol, hole, 0, -1, dist, path + "l", res);
        if (dc == 0) roll(maze, ballRow, ballCol, hole, 0, 1, dist, path + "r", res);
        if (dr == 0) roll(maze, ballRow, ballCol, hole, -1, 0, dist, path + "u", res);
      }
    }
    return res.first;
  }
public:
  string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole){
    return roll(maze, ball[0], ball[1], hole, 0, 0, 0, "", pair<string, int>() = {"impossible", INT_MAX});
  }
};

int main(){
	vector<vector<int>> maze1 = {{0, 0, 0, 0, 0},
                               {1, 1, 0, 0, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 0, 0, 1},
                               {0, 1, 0, 0, 0}};
	vector<int> ball1 = {4, 3};
	vector<int> hole1 = {3, 0};
	vector<vector<int>> maze2 = {{0, 0, 0, 0, 0},
                               {1, 1, 0, 0, 1},
                               {0, 0, 0, 0, 0},
                               {0, 1, 0, 0, 1},
                               {0, 1, 0, 0, 0}};
	vector<int> ball2 = {4, 3};
	vector<int> hole2 = {0, 1};
  vector<vector<int>> maze3 = {{0}, {1}};
  vector<int> ball3 = {0, 0};
  vector<int> hole3 = {1, 0};
	Solution sol;
	cout << sol.findShortestWay(maze2, ball2, hole2) << endl;
	cout << sol.findShortestWay(maze1, ball1, hole1) << endl;
  cout << sol.findShortestWay(maze3, ball3, hole3) << endl;
  return 0;
}
