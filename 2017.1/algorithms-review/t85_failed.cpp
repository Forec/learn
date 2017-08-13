#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
  struct cell{
    int left;
    int right;
    cell(): left(0), right(0) {};
    cell(int x, int y): left(x), right(y) {};
  };
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int maximalRectangle(vector<vector<char>>& matrix){
    if (matrix.size() == 0 || matrix[0].size() == 0)
      return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<cell>> map(m, vector<cell>(n, cell(0, 0)));
    int last = 0;
    for (int i = 0; i < n; i++){
      if (matrix[0][i] == '0'){
        map[0][i] = cell(0, 0);
        last = 0;
      } else {
        map[0][i] = cell(++last, 1);
      }
    }
    for (int i = 1; i < m; i++){
      for (int j = 0; j < n; j++){
        if (matrix[i][j] == '0')
          continue;
        int k = 1, left = 1, right = 1;
        while (i - k >= 0 && matrix[i-k][j] == '1')
          k++; // vertical scanning
        left = k; k = 1;
        while (j - k >= 0 && matrix[i][j-k] == '1')
          k++; // horizontal scanning
        right = k;
        cell upper = map[i-1][j];
        int maxleft = max(left, upper.left), maxright = max(right, upper.right);
        int minleft = min(left, upper.left), minright = min(right, upper.right);
        int area1 = minleft * maxright, area2 = minright * maxleft;
        if (area1 > area2){
          map[i][j] = cell(minleft, maxright);
        } else {
          map[i][j] = cell(maxleft, minright);
        }
      }
    }
    cell ans = map[m - 1][n - 1];
    return ans.left * ans.right;
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
