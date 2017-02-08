#include <iostream>
#include <vector>
using namespace std;

/*
  f[k, i] represents the max profit up until prices[i]
  f[k, i] = max{ f[k, i-1], f[k-1, j] + prices[i] - prices[j] }
          = max{ f[k, i-1], prices[i] + max{ f[k-1, j] - prices[j] } } // notice the inside max can be record during one loop
  f[k, 0] = 0
  f[0, i] = 0
 */

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int K = 2;
    int res = 0;
    vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
    for (int k = 1; k <= K; k++){
      int insideMax = f[k - 1][0] - prices[0];
      for (int i = 1; i < prices.size(); i++){
        f[k][i] = max(f[k][i-1], prices[i] + insideMax);
        insideMax = max(insideMax, f[k-1][i] - prices[i]);
        res = max(res, f[k][i]);
      }
    }
    return res;
  }
};

// another wonderful solution: 4 states to maintain
class Solution2{
public:
  int maxProfit(vector<int> prices){
    int hold1 = INT_MIN, hold2 = INT_MIN;
    int relase1= 0, release2 = 0;
    for (int i: prices){
      release2 = max(release2, hold2 + i);
      hold2    = max(hold2,    release1 - i);
      release1 = max(release1, hold1 + i);
      hold1    = max(hold1,    -i);
    }
    return release2;
  }
}

int main(){
  vector<int> para ={7, 1, 3, 5, 3, 7};
  vector<int> para2 = {3, 3, 5, 0, 0, 3, 1, 4};
  Solution sol;
  cout << sol.maxProfit(para2) << endl;
  return 0;
}
