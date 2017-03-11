#include <iostream>
#include <vector>
#include <string>
#include "test/quickcheck.h"

using namespace std;

// 1 -> A
// 26 -> Z   26 % 26 = 0
// 27 -> AA  27 % 26 = 1, 27 / 26 = 1
// 26 * 26 -> ZZ  26 * 26 % 26 = 0, 26 % 26= 0
// 26 * 26 + 1 -> AAA 

// step1: (n - 1) % 26 = last char
// step2: (n - 1) / 26 = next n

class Solution {
public:
  string convertToTitle1(int n) {
    if (n == 0)
      return "";
    string pre = convertToTitle((n-1) / 26);
    pre += ('A' + (n-1) % 26);
    return pre;
  }
  string convertToTitle(int n){
    string res = "";
    while (n > 0){
      n--;
      res.insert(res.begin(), 'A' + (n % 26));
      n /= 26;
    }
    return res;
  }
  string run(int n){
    return convertToTitle(n);
  }
};

int main(){
  vector<int> inputs = {1, 26, 27, 26*26+26, 26*26+26+1};
  vector<string> outputs = {"A", "Z", "AA", "ZZ", "AAA"};
  QuickCheck<int, string, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
