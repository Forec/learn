#include <iostream>
using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ans = 0;
    for (char cx = 31 ; cx >= 0; cx--){
      ans |= ((n & 1) << cx);
      n >>= 1;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  cout << sol.reverseBits(43261596 )<< endl;
  return 0;
}
