#include <iostream>
#include <vector>
#include "test/quickcheck.h"
using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int sum = 0;
    while (n >= 5){
      sum += n / 5;
      n /= 5;
    }
    return sum;
  }
  int run(int n){
    return trailingZeroes(n);
  }
};

int main (){
  vector<int> inputs = {1, 3, 4, 5, 10, 15};
  vector<int> outputs = {0, 0, 0, 1, 2, 3};
  QuickCheck<int, int, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
