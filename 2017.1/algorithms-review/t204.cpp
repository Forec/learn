#include <iostream>
#include <vector>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    if (n <= 2)
      return 0;
    isPrime[0] = isPrime[1] = false;
    int count = 0;
    for (int i = 2; i < n; i++){
      if (isPrime[i]){
        for (int j = i+i; j < n; j+=i)
          isPrime[j] = false;
        count++;
      }
    }
    return count;
  }
  int run(int n){
    return countPrimes(n);
  }
};

int main(){
  vector<int> inputs = {2, 4, 5, 7, 11};
  vector<int> outputs = {0, 2, 2, 3, 4};
  Solution sol;
  QuickCheck<int, int, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
