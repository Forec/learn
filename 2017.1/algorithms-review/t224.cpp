#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  int calculate(string s) {
    vector<string> init;
    int i = 0;
    while (i < s.length()){
      if (s[i] == '('){
        int count = 1;
        int j = i + 1;
        while (count != 0){
          if (s[j] == '(')
            count++;
          if (s[j] == ')')
            count--;
          j++;
        }
        int subans = calculate(s.substr(i+1, j-i-2));
        init.push_back(to_string(subans));
        i = j;
      } else if ('0' <= s[i] && s[i] <= '9'){
        int j = i + 1;
        while ('0' <= s[j] && s[j] <= '9')
          j++;
        init.push_back(s.substr(i, j-i));
        i = j;
      } else {
        if (s[i] != ' ')
          init.push_back(s.substr(i, 1));
        i++;
      }
    }

    stringstream ss;
    ss << init[0];
    int ans1;
    ss >> ans1;
    for (i = 1; i < init.size(); i+=2){
      stringstream st;
      char op = init[i][0];
      st << init[i+1];
      int ans2;
      st >> ans2;
      if (op == '+')
        ans1 += ans2;
      else
        ans1 -= ans2;
    }
    return ans1;
  }
  int run(string s){
    return calculate(s);
  }
};

int main (){
  vector<string> inputs = {"0", "1 + 1", " 2-1 + 2 ", "(1+(4+5+2)-3)+(6+8)"};
  vector<int> ans = {0, 2, 3, 23};
  QuickCheck<string, int, Solution> q(inputs, ans);
  q.runTests();
  return 0;
}
