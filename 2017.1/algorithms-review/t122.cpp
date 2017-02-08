#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int sum = 0;
    for (int i = 1; i < prices.size(); i++){
      if (prices[i] > prices[i-1])
        sum += (prices[i] - prices[i-1]);
    }
    return sum;
  }
};

int main(){
  vector<int> para = {7, 6, 4, 3, 1};
  vector<int> para2 = {7, 1, 4, 5, 3, 6};
  Solution sol;
  cout << sol.maxProfit(para) << " " << sol.maxProfit(para2) << endl;
  return 0;
}
