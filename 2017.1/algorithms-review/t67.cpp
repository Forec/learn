#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    if (a.length() == 0)
      return b;
    if (b.length() == 0)
      return a;
    stringstream ans;
    int i = a.length() - 1, j = b.length() -1, c = 0;
    while (i >= 0 && j >= 0){
      int ai = a[i] - '0', bj = b[j] - '0';
      int sum = ai + bj + c;
      if (sum > 1){
        sum -= 2;
        c = 1;
      } else {
        c = 0;
      }
      ans << sum;
      i--; j--;
    }
    while (i >= 0){
      int sum = a[i] - '0' + c;
      if (sum > 1){
        sum -= 2;
        c = 1;
      } else {
        c = 0;
      }
      ans << sum;
      i--;
    }
    while (j >= 0){
      int sum = b[j] - '0' + c;
      if (sum > 1){
        sum -= 2;
        c = 1;
      } else {
        c = 0;
      }
      ans << sum;
      j--;
    }
    if (c == 1)
      ans << 1;
    string res = ans.str();
    reverse(res.begin(), res.end());
    return res;
  }
};

int main(){
  string a = "1";
  string b = "01";
  Solution sol;
  cout << sol.addBinary(a, b) << endl;
  return 0;
}
