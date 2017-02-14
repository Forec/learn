#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
  string convertTo7(int num) {
    if (num == 0){
      return "0";
    }
    bool flag = false;
    if (num < 0){
      flag = true;
      num = -num;
    }
    string ans = "";
    while (num != 0){
      int odd = num % 7;
      num /= 7;
      ans = to_string(odd) + ans;
    }
    if (flag){
      ans = "-" + ans;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  cout << sol.convertTo7(100) << endl;
  cout << sol.convertTo7(-7) << endl;
  cout << sol.convertTo7(-1) << endl;
  return 0;
}
