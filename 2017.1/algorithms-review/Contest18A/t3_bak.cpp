#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    vector<vector<int>> pure(Profits.size(), vector<int>(2, 0));
    for (int i = 0; i < Profits.size(); i++){
      pure[i][0] = Profits[i];
      pure[i][1] = Capital[i];
    }
    sort(pure.begin(), pure.end());
    int sum = W;
    while (k > 0){
      bool find = false;
      for (int i = pure.size() - 1; i >= 0; i--){
        //        cout << i << " " << pure[i][1] << " " << pure[i][0] << endl;
        if (pure[i][0] <= 0)
          break;
        if (pure[i][1] <= sum){
          find = true;
          sum += pure[i][0];
          pure.erase(pure.begin() + i);
          break;
        }
      }
      if (!find)
        break;
      k--;
    }
    return sum;
  }
};

int main(){
  Solution sol;
  vector<int> caps = {0, 1, 1, 4, 2, 1};
  vector<int> pro = {2, 2, 3, 5, 10, 12};
  cout << sol.findMaximizedCapital(0, 3, pro, caps) << endl;
  return 0;
}
