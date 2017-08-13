#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
  bool isMatch(string s, string p){
    int m = s.length(), n = p.length();
    int i = 0, j = 0, star = -1, match;
    while ( i < m ){
      if (j < n && p[j] == '*'){
        match = i;
        star = j++;
      } else if (j < n && (s[i] == p[j] || p[j] == '?')){
        i++;
        j++;
      } else if (star >= 0){
        i = ++match;
        j = star + 1;
      } else
        return false;
    }
    while (j < n && p[j] == '*') j++;
    return j == n;
  }
};

int main(){
  string s = "aab";
  string p = "*a*b";
  Solution sol;
  cout << sol.isMatch(s, p) << endl;
  return 0;
}
