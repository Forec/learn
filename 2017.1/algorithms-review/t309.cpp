#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int maxProfit(vector<int>& data){
    int k = 1;
    int n = data.size();
    if (n < 2)
      return 0;
    vector<int> dp(n+k, 0);
    int sum = -data[0];
    for (int i = k; i < n; i++){
      dp[i+1] = max(dp[i], sum + data[i]);
      sum = max(sum, dp[i-k] - data[i]);
    }
    return dp[n];
  }
};

int main(){
  vector<int> para = {1, 2, 3, 0, 2};
  Solution sol;
  cout << sol.maxProfit(para) << endl;
  return 0;
}
