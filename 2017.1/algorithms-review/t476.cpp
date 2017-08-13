#include <iostream>
using namespace std;

class Solution {
public:
  int findComplement(int num) {
    int mask = ~0;
    while (num & mask) mask <<= 1;
    return (~num) & (~mask);
  }
};

int main(){
  Solution sol;
  cout << sol.findComplement(5) << " " << sol.findComplement(1) << endl;
  return 0;
}
