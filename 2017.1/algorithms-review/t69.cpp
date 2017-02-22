#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    long long r = x;
    while (r *r > x)
      r = (r + x / r) / 2;
    return r;
  }
};

int main(){
  Solution sol;
  cout << sol.mySqrt(4) << " " << sol.mySqrt(1) << " " << sol.mySqrt(1000000000) << " " << sol.mySqrt(0) <<endl;
  return 0;
}
