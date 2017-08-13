#include <iostream>
#include <string>
#include <unordered_map>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  string fractionToDecimal(int _numerator, int _denominator) {
    if (_numerator == 0)
      return "0";
    string res = "";
    int64_t numerator = _numerator;
    int64_t denominator = _denominator;
    if ((numerator < 0) ^ (denominator < 0))
      res += "-";
    long long n = abs(numerator);
    long long d = abs(denominator);
    res += to_string(n / d);
    if (n % d == 0)
      return res;
    res += ".";
    unordered_map<int, int> pos;
    for (int64_t r = n % d; r != 0; r %= d){
      if (pos.count(r) > 0){
        res.insert(pos[r], 1, '(');
        res += ")";
        return res;
      }
      pos[r] = res.size();
      r *= 10;
      res += to_string(r / d);
    }
    return res;
  }
  string run(PAIR<int, int>& p){
    return fractionToDecimal(p.first, p.second);
  }
};

int main(){
  vector<PAIR<int, int>> inputs = {PAIR<int, int>(1, 2),
                                   PAIR<int, int>(2, 1),
                                   PAIR<int, int>(2, 3),
                                   PAIR<int, int>(-2147483648, -1),
                                   PAIR<int, int>(1, 6),
                                   PAIR<int, int>(1, 333)};
  vector<string> ans = {"0.5", "2", "0.(6)", "2147483648", "0.1(6)", "0.(003)"};
  QuickCheck<PAIR<int, int>, string, Solution> q(inputs, ans);
  q.runTests();
  return 0;
}
