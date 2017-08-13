#include <iostream>
#include <string>
using namespace std;

//regexp = [-+]?(([0-9]+(.[0-9]*)?)|.[0-9]+)(e[-+]?[0-9]+)?

class Solution{
public:
  bool isNumber(string s){
    int index = 0;
    while (index < s.length() && s[index] == ' ') index++;
    if (s[index] == '+' || s[index] == '-') index++;
    int numCountBeforeDot = 0, dotCount = 0;
    while (index < s.length() && (s[index] >= '0' && s[index] <= '9' || s[index] == '.')){
      if (s[index] == '.')
        dotCount ++;
      else
        numCountBeforeDot ++;
      index++;
    }
    if (numCountBeforeDot < 1 || dotCount > 1)
      return false;
    if (s[index] == 'e'){
      index++;
      if (s[index] == '+' || s[index] == '-') index++;
      int numCountAfterE = 0;
      while (index < s.length() && (s[index] >= '0' && s[index] <= '9')){
        numCountAfterE ++;
        index++;
      }
      if (numCountAfterE < 1)
        return false;
    }
    while (index < s.length() && s[index] == ' ')
      index++;
    return index == s.length();
  }
};

int main(){
  Solution sol;
  cout << sol.isNumber("3") << endl;
  return 0;
}
