#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1)
      return 0;
    vector<int> dp(prices.size(), 0);
    dp[0] = 0;
    int maxm = 0;
    for (int i = 1; i < prices.size(); i++){
      int inc = prices[i] - prices[i-1];
      if (inc + dp[i-1] > 0){
        dp[i] = dp[i-1] + inc;
      } else {
        dp[i] = max(0, inc);
      }
      maxm = max(dp[i], maxm);
    }
    return maxm;
  }
};

int main(){
  vector<int> para = {7, 1, 5, 3, 6, 4};
  vector<int> para2 = {7, 6, 4, 3, 1};
  Solution sol;
  cout << sol.maxProfit(para2) <<endl;
  return 0;
}
