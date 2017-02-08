#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
private:
  struct cell{
    int p;
    int cap;
    cell(int _p, int _cap):p(_p), cap(_cap){};
  };
  // bool comp_cell(const cell &x, const cell & y){
  //   return x.p > y.p;
  // }
public:
  int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    vector<cell> pure(Profits.size(), cell(0, 0));
    for (int i = 0; i < Profits.size(); i++){
      pure[i].p = Profits[i] - Capital[i];
      pure[i].cap = Capital[i];
    }
    sort(pure.begin(), pure.end(), comp_cell);
    int sum = W;
    while (k > 0){
      bool find = false;
      for (int i = 0; i < pure.size(); i++){
        cout << i << " " << pure[i].cap << " " << pure[i].p << endl;
        if (pure[i].p <= 0)
          break;
        if (pure[i].cap <= sum){
          find = true;
          sum += pure[i].p;
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
  vector<int> pro = {1, 2, 3, 5, 0, 3}; // 1, 1, 2, 1, -2, 2
  cout << sol.findMaximizedCapital(2, 0, pro, caps) << endl;
  return 0;
}
