#include <iostream>
#include <vector>
#include <string>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int base = 1;
    int ans = 0;
    for (int i = s.length() - 1; i >= 0; i--){
      ans += (s[i] - 'A' + 1) * base;
      base *= 26;
    }
    return ans;
  }
  int run(string s){
    return titleToNumber(s);
  }
};

int main(){
  vector<string> intputs= {"AB", "A", "Z", "ZZ", "AAA"};
  vector<int> outputs = {28, 1, 26, 26*26+26, 26*26+26+1};
  QuickCheck<string ,int ,Solution> q(intputs, outputs);
  q.runTests();
  return 0;
}
