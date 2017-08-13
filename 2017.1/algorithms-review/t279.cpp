#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for (int i =0; i <= n; i++){
      for (int j  =1; i + j*j <= n; j++){
        dp[i + j*j] = min(dp[i +j*j], dp[i] + 1);
      }
    }
    return dp[n];
  }
};

int main(){
  Solution sol;
  cout << sol.numSquares(12) << endl;
  return 0;
}
