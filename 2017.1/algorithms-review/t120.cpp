#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    if (triangle.size() == 0) return 0;
    vector<int> dp(triangle[triangle.size()-1]);
    for (int j = triangle.size() - 2; j >= 0; j--){
      for (int i = 0 ; i <= j; i++){
        dp[i] = min(dp[i], dp[i+1]) + triangle[j][i];
      }
    }
    return dp[0];
  }
};

int main(){
  Solution sol;
  vector<vector<int>> para= {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
  cout << sol.minimumTotal(para) <<endl;
  return 0;
}
