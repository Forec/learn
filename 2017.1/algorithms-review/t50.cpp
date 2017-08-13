#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    double base = 1;
    unsigned long long fuckingN;
    if (n == 0) return 1;
    if (n < 0) {
      fuckingN = -n;
      x = 1.0 / x;
    } else {
      fuckingN = n;
    }
    while (fuckingN){
      if (fuckingN&1)
        base *= x;
      fuckingN >>= 1;
      x *= x;
    }
    return base;
  }
};

int main(){
  Solution sol;
  cout << sol.myPow(3, 7) << endl;
  cout << sol.myPow(2, 4) << endl;
  cout << sol.myPow(1, 1) << endl;
  cout << sol.myPow(4, 9) << endl;
  cout  << sol.myPow(0, 0) << endl;
  cout << sol.myPow(34.00515, -3) << endl;
  cout << sol.myPow(8.84382, -5) << endl;
  cout << sol.myPow(2.000000, -2147483648) << endl;
  return 0;
}
