#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    // You are such a fucking asshole
    // There is no need to check
    // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1])+1
    if (matrix.empty())
      return 0;
    int m = matrix.size(), n = matrix[0].size(), maxA = 0;
    vector<int> height(n, 0);
    for (int i = 0; i < n; i++)
      if (matrix[0][i] == '1') {
        height[i] = 1;
        maxA = 1;
      }
    height.erase(height.begin());
    for (int i = 1; i < m; i++) {
      if (matrix[i - 1][0] == '1') {
        height.insert(height.begin(), 1);
        if (maxA == 0)
          maxA = 1;
      } else
        height.insert(height.begin(), 0);
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == '0') {
          height[j-1] = 0;
          continue;
        }
        int cp = height[j - 1], k = 1;
        while (i - k >= 0 && j - k >= 0 && matrix[i - k][j] == '1' &&
               matrix[i][j - k] == '1')
          k++;
        height[j-1] = min(cp + 1, k);
        if (maxA < height[j-1]) {
          maxA = height[j-1];
          //          cout << i << " " << j << " " << height[j-1] << " " <<cp << endl;
        }
      }
      height.pop_back();
    }
    return maxA * maxA;
  }
};

int main() {
  Solution sol;
  vector<vector<char>> map4 = {{'0', '1', '0', '1', '0', '0'},
                               {'0', '0', '1', '1', '0', '1'}}; // 1
  vector<vector<char>> map2 = {{'1', '0', '1', '0'},
                               {'1', '0', '1', '1'},
                               {'1', '0', '0', '1'},
                               {'1', '1', '1', '1'}}; // 1
  vector<vector<char>> map = {{'1', '1', '1', '1', '0'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'}}; // 16
  vector<vector<char>> map1 = {{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'}}; //4
  vector<vector<char>> map5 = {{'1', '1', '1', '1', '0'},
                               {'1', '1', '1', '1', '1'},
                               {'1', '0', '1', '1', '1'},
                               {'1', '1', '1', '1', '1'}}; // 9
  vector<vector<char>> map3 = {{'1'}}; // 1
  cout << (sol.maximalSquare(map3)) << endl; // 1
  cout << (sol.maximalSquare(map2)) << endl; // 1
  cout << (sol.maximalSquare(map) ) << endl; // 16
  cout << (sol.maximalSquare(map4)) << endl; // 1
  cout << (sol.maximalSquare(map1)) << endl; // 4
  cout << (sol.maximalSquare(map5)) << endl; // 9
  return 0;
}
