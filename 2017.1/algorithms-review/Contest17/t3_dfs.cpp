#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node{
	int ballX;
	int ballY;
	int dist;
	string path;
};

class Solution {
private:
	vector<vector<int>> directions = {{0, 1}, {-1, 0}, {1, 0}, {0, -1}}; // d,l,r,u
	vector<string> dirName = {"d", "l", "r", "u"};
	int holeX, holeY;
	int width, height;
	string dfs(vector<vector<int>> &maze, node ball){

		node temp = ball;
		cout << ball.ballX << " " << ball.ballY << " " << ball.dist
		for (int i = 0; i < 4; i++){
			ball = temp;
			ball.path = ball.path + dirName[i];
			while (ball.ballX >= 0 && ball.ballX < width && ball.ballY >= 0 && ball.ballY < height){
				if (maze[ball.ballY][ball.ballX] == 1){
					ball.ballY -= directions[i][1];
					ball.ballX -= directions[i][0];
					string ans = dfs(maze, ball);
					if (ans != "impossible"){
						return ans;
					} else {
						break;
					}
				} else {
					if (ball.ballX == holeY && ball.ballY == holeX){
						return ball.path;
					}
					ball.ballX += directions[i][0];
					ball.ballY += directions[i][1];
					ball.dist ++;
				}
			}
		}
		return "impossible";
	}
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		node x;
		height = maze.size();
		width = maze[0].size();
		// build the border
		for (int i = 0; i < maze.size(); i++){
			maze[i].insert(maze[i].begin(), 1);
			maze[i].push_back(1);
		}
		vector<int> border(width + 2, 1);
		maze.push_back(border);
		maze.insert(maze.begin(), border);
		width += 2;
		height += 2;
		holeX = hole[0] + 1;
		holeY = hole[1] + 1;
		x.ballX = ball[1] + 1; x.ballY = ball[0] + 1; x.dist = 0; x.path = "";
		return dfs(maze, x);
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
	Solution sol;
	cout << sol.findShortestWay(maze2, ball2, hole2) << endl;
	cout << sol.findShortestWay(maze1, ball1, hole1) << endl;
	return 0;
}
