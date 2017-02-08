#include <iostream>
using namespace std;

class Solution {
public:
  bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
      //      (num & 0x55555555) != 0;
    // proof: #1: 4^n -1 = (4-1)(4^(n-1) + 4^(n-2) + 4^(n-3) + ... + 4 + 1)
    //        #2: 4^(n+1) - 1 = 4* 4^n - 1 = 3(4^n) + 4^n -1
    //        #3: 4^1 - 1 = 3 % 3 == 0

    // what about magic number? 1. num > 0 is necessary
    // 2. num & (num-1) ensures there's exactly one bit 1 in binary mode
    // 3. since the num is expected to be 4^n, the bit 1 must be in the odd location. So we can use 0x55555555 to check
    // the position of bit 1.
  }
};

int main(){
  Solution sol;
  for (int i = 4; i < INT_MAX/4; i*=4){
    cout << sol.isPowerOfFour(i) << " " << sol.isPowerOfFour(i+1) <<
      " " << sol.isPowerOfFour(i+2) << endl;
  }
  return 0;
}
