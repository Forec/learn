#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0, total = 0, current = 0;
    for (int i = 0; i < gas.size(); i++){
      current += gas[i] - cost[i];
      if (current < 0){
        start = i + 1;
        current = 0;
      }
      total += gas[i] - cost[i];
    }
    if (total < 0){
      return -1;
    }
    return start;
  }
};

int main(){
  Solution sol;
  vector<int> gas = {4};
  vector<int> cost = {5};
  int ans1 = sol.canCompleteCircuit(gas, cost);
  cout << ans1 << endl; // 0 1
  return 0;
}
