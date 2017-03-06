#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    stringstream ss;
    for (int i = 0; i < s.length(); i++){
      if (isalnum(s[i]))
        ss << char(tolower(s[i]));
    }
    string build = ss.str();
    if (build.empty())
      return true;
    int i = 0, j = build.length() - 1;
    while (i < j){
      if (build[i++] != build[j--])
        return false;
    }
    return true;
  }
  bool run(string s){
    return isPalindrome(s);
  }
};

int main(){
  vector<string> input = {"A man, a plan, a canal: Panama", "race a car", "0P"};
  vector<bool> output = {true, false, false};
  QuickCheck<string, bool, Solution> *q = new QuickCheck<string, bool, Solution>(input, output);
  q->runTests();
  return 0;
}
