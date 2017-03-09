#include <iostream>
#include <vector>
#include <string>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  void reverseWords(string &s) {
    string ans = "";
    int i = 0, j = 0;
    while (j < s.length()){
      while (i < s.length() && s[i] == ' ') i++;
      j = i;
      while (j < s.length() && s[j++] != ' ');
      if (i == j)
        break;
      if (ans == ""){
        ans = s.substr(i, j == s.length() && s[j-1] != ' '? j - i :  j-i-1);
      } else {
        ans = (s.substr(i, j == s.length() && s[j-1] != ' ' ? j - i :j-i-1) + " ") + ans;
      }
      i = j;
    }
    s = ans;
  }
  string run(string &s){
    string p = s;
    reverseWords(p);
    return p;
  }
};

int main (){
  vector<string> inputs = {"the sky is blue", "      I want to fuck    a shit    ", "1 "};
  vector<string> outputs = {"blue is sky the", "shit a fuck to want I", "1"};
  QuickCheck<string, string, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
