#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> appeared;
    while (n != 1 && appeared.count(n) == 0){
      appeared.insert(n);
      string str = to_string(n);
      int sum = 0;
      for (int i = 0; i < str.length(); i++){
        sum += (str[i] - '0') * (str[i] - '0');
      }
      n = sum;
    }
    if (n == 1)
      return true;
    return false;
  }
  bool run(int n){
    return isHappy(n);
  }
};

int main(){
  Solution sol;
  vector<int> inputs= {19};
  vector<bool> outputs = {true};
  QuickCheck<int, bool, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
