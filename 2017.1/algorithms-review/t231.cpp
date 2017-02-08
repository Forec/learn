#include <iostream>
using namespace std;

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n < 0)
      return false;
    if (n != 1 && n&1)
      return false;
    bool find1 = false;
    while (n > 0){
      if (n & 1 && find1)
        return false;
      else if (n & 1)
        find1 = true;
      n >>= 1;
    }
    return find1;
  }
};

int main(){
  Solution sol;
  for(int i = -2; i < 9; i++){
    cout  << i<< " " << sol.isPowerOfTwo(i) << endl;
  }
  return 0;
}
