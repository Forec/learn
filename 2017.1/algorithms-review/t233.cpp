#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
  int much(long long n, long long len, long long base) {
    //    cout << n << " " << len << " " << base << endl;
    if (len == 1)
      return n >= 1;
    else {
      int sum = 0;
      if (n / base > 1) {
        sum += base;
      } else {
        sum += n - base + 1;
      }
      int pre = much(base - 1, len - 1, base / 10);
      long long next = n % base, tmp = next;
      long long base2 = 1, len2 = 1;
      while (next >= 10){
        base2 *= 10;
        len2 ++;
        next /= 10;
      }
      sum += (n / base) * pre + (tmp == 0 ? 0 : much(tmp, len2, base2));
      return sum;
    }
  }
public:
  int countDigitOne(int n) {
    long long tn = n;
    if (tn <= 0)
      return 0;
    long long tmp = tn;
    long long base = 1, len = 1;
    while (tn >= 10){
      len ++;
      base *= 10;
      tn /= 10;
    }
    return much(tmp, len, base);
  }
};

int main(){
  Solution sol;
  cout << (sol.countDigitOne(13)==6) << endl;
  cout << (sol.countDigitOne(100)==21) << endl;
  cout << (0==sol.countDigitOne(0)) << endl;
  cout << (sol.countDigitOne(101)==23) << endl;
  cout << sol.countDigitOne(1000000000) << endl;
  cout << (0==sol.countDigitOne(-1)) << endl;
  return 0;
}
