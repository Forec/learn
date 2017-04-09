#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    auto l = s.begin(), r = s.begin();
    while (true){
      while (r != s.end() && (*r) != ' '){
        r++;
      }
      reverse(l, r);
      if (r == s.end())
        break;
      l = r+1;
      r++;
    }
    return s;
  }
};


int main(){
  Solution sol;
  string s1 = "Let's take LeetCode contest";
  string s2 = "fuck you shit";
  string s3 = "";
  string s4 = "f";
  string s5 = "fasjlfs";
  cout << (sol.reverseWords(s1)=="s'teL ekat edoCteeL tsetnoc") << endl;
  cout << (sol.reverseWords(s2)=="kcuf uoy tihs") << endl;
  cout << (sol.reverseWords(s3)=="") << endl;
  cout << (sol.reverseWords(s4)=="f") << endl;
  cout << (sol.reverseWords(s5)=="sfljsaf") << endl;
  return 0;
}
