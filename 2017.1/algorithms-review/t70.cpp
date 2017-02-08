#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 0) return 0;
    if (n <= 2) return n;
    int dp1 = 1, dp2 = 2;
    for (int i = 3; i <= n; i++){
      int tmp = dp2;
      dp2 += dp1;
      dp1 = tmp;
    }
    return dp2;
  }
};

int main(){
  Solution sol;
  cout << sol.climbStairs(4) <<endl;
  return 0;
}
