#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int rangeBitwiseAnd(int m, int n) {
    if (m == 0 || m == n) return m;
    long long rangeLeft = 1, rangeRight = 1;
    while ((rangeLeft << 1)<= m){
      rangeLeft <<= 1;
      rangeRight <<= 1;
    }
    int sub = 0;
    while (rangeRight <= n){
      sub++;
      rangeRight <<= 1;
    }
    if (sub == 1){
      if (rangeLeft < 16){
        int res = m;
        for (int i = m+1; i <= n; i++)
          res &= i;
        return res;
      } else {
        int res = rangeLeft;
        return res | rangeBitwiseAnd(m-rangeLeft, n - rangeLeft);
      }
    } else {
      return 0;
    }
  }
};

int main(){
  Solution sol;
  cout << (sol.rangeBitwiseAnd(2, 3)==2) << endl;
  cout << (sol.rangeBitwiseAnd(1, 2)==0) << endl;
  cout << (sol.rangeBitwiseAnd(0, 2147483647)==0) << endl;
  cout << (sol.rangeBitwiseAnd(1, 2147483647)==0) << endl;
  cout << (sol.rangeBitwiseAnd(2, 2)==2) << endl;
  cout << (sol.rangeBitwiseAnd(16, 32)==0) << endl;
  return 0;
}
