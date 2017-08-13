#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op) {
      if (op == '+' or op == '-') {
        total += term;
        in >> term;
        term *= 44 - op;
      } else {
        in >> n;
        if (op == '*')
          term *= n;
        else
          term /= n;
      }
    }
    return total;
  }
};

int main(){
  string para = "3*7+2*5/4+5-6";
  Solution sol;
  cout << sol.calculate(para) << endl;
  return 0;
}
