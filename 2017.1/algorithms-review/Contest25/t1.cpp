#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../test/quickcheck.h"
using namespace std;

class Solution {
public:
  bool checkPerfectNumber(int num) {
    if (num <= 1)
      return false;
    int sum = 1;
    int sqr = sqrt(num);
    for (int i = 2; i <= sqr; i++){
      if (num % i == 0){
        sum += i;
        if (num / i != i)
          sum += num / i;
      }
    }
    return sum == num;
  }
  bool run(int num){
    return checkPerfectNumber(num);
  }
};

int main(){
  Solution sol;
  vector<int> inputs = {0, 1, 2, 3, 4, 6, 10, 28, 100, 256};
  vector<bool> outputs = {false, false, false, false, false,true, false, true, false, false};
  QuickCheck<int, bool, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
