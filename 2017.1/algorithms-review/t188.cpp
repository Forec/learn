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
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int maxProfit(int kk, vector<int>& prices) {
    if (prices.size() <= 1) return 0;
    int K = min(kk, prices.size() / 2 + 1), temp;
    int res = 0;
    vector<int> fk(prices.size(), 0);
    for (int k = 1; k <= K; k++){
      int insideMax = fk[0] - prices[0];
      for (int i = 1; i < prices.size(); i++){
        temp = fk[i];
        fk[i] = max(fk[i-1], prices[i] + insideMax);
        insideMax = max(insideMax, temp - prices[i]);
        res = max(res, fk[i]);
      }
    }
    return res;
  }
};

int main(){
  vector<int> para ={7, 1, 3, 5, 3, 7};
  vector<int> para2 = {3, 3, 5, 0, 0, 3, 1, 4};
  Solution sol;
  cout << sol.maxProfit(2, para2) << endl;
  return 0;
}
