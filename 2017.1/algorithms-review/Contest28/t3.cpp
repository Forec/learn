#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
  bool checkRecord(string s) {
    int count = 0;
    int pre = 0;
    for (int i = 0; i < s.length(); i++){
      if (s[i] == 'A'){
        count ++;
        if (count > 1)
          return false;
        pre = 0;
      }
      else if (s[i] == 'L'){
        if (pre == 2)
          return false;
        else
          pre ++;
      }
      else {
        pre = 0;
      }
    }
    return true;
  }
};

int main(){
  Solution sol;
  cout << sol.checkRecord("PPALLP") << endl;
  cout << sol.checkRecord("PPALLL") << endl;
  return 0;
}
