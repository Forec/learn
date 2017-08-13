#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

class Solution{
private:
  int largestRectangleArea(vector<int> &height){
    stack<int> s;
    height.push_back(0);
    int sum = 0, i = 0;
    while (i < height.size()){
      if (s.empty() || height[i] > height[s.top()]){
        s.push(i++);
      } else {
        int t = s.top();
        s.pop();
        sum = max(sum, height[t] * (s.empty()? i : (i - s.top() - 1)));
      }
    }
    return sum;
  }
public:
  int maximalRectangle(vector<vector<char>> &matrix){
    if (matrix.empty() || matrix[0].empty()){
      return 0;
    }
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> height(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++){
      for (int j = 0; j < n; j++){
        if (matrix[i][j] == '0')
          height[i][j] = 0;
        else
          height[i][j] = (i == 0) ? 1 : height[i-1][j] + 1;
      }
    }
    int maxArea = 0;
    for (int i = 0; i < m; i++){
      maxArea = max(maxArea, largestRectangleArea(height[i]));
    }
    return maxArea;
  }
};


int main(){
  Solution sol;
  vector<vector<char>> map = {{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};
  cout << sol.maximalRectangle(map) << endl;
  return 0;
}
