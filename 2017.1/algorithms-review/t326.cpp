#include <iostream>
using namespace std;

class Solution {
public:
  int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
  bool isPowerOfThree(int n) {
    if (n <= 0 || n > Max3PowerInt) return false;
    return Max3PowerInt % n == 0;
  }
};

int main(){
  Solution sol;
  for (int i = 3; i < INT_MAX/3; i*=3){
    cout << sol.isPowerOfThree(i) << " " << sol.isPowerOfThree(i+1) << endl;
  }
  return 0;
}
