#include <iostream>

using namespace std;

class Solution {
public:
  int addDigits(int num) {
    return 1 + (num - 1) % 9;
  }
};

int main(){
  Solution sol;
  cout << sol.addDigits(65536) << endl;
  cout << sol.addDigits(38) << endl;
  return 0;
}
