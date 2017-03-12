#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  string reverseStr(string s, int k) {
    if (k <= 1)
      return s;
    char c;
    for (int i = 0; i < s.length(); i+= 2*k){
      int seg = k;
      if (i + k > s.length()){
        seg = s.length() - i;
      }
      for (int j = 0; j < seg/2; j++){
        c = s[i+j];
        s[i+j] = s[i+seg-1-j];
        s[i+seg-1-j] = c;
      }
    }
    return s;
  }
};


int main(){
  Solution sol;
  cout << (sol.reverseStr("abcdefg",2)=="bacdfeg") << endl;
  cout << (sol.reverseStr("abcdefg",3)=="cbadefg") << endl;
  cout << (sol.reverseStr("abcdefgklfdsaklj",1)=="abcdefgklfdsaklj") << endl;
  cout << (sol.reverseStr("abcdefgklfdsakljsf",4) =="dcbaefgksdflakljfs") << endl;
  return 0;
}
