#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution1 {
private:
  int _numDecodings(string s){
    if (s.length() == 0) return 1;
    if (s.length() == 1 && s[0] != '0')
      return 1;
    if (s[0] == '0')
      return 0;
    if (s[0] == '1' || s[0] == '2'){
      if (s[0] == '2' && s[1] - '0' > 6 || s[1] == '0'){
        return _numDecodings(s.substr(2));
      } else {
        return _numDecodings(s.substr(1)) + _numDecodings(s.substr(2));
      }
    } else {
      return _numDecodings(s.substr(1));
    }
  }
public:
  int numDecodings(string s) {
    if (s.length() == 0)
      return 0;
    return _numDecodings(s);
  }
};

class Solution {
public:
  int numDecodings(string s){
    int n = s.length();
    if (n == 0) return 0;
    vector<int> ways(n+1, 0);
    ways[n] = 1;
    for (int i = n-1; i >= 0; i--){
      if (s[i] == '0')
        ways[i] = 0;
      else if (i == n-1){
        ways[i] = 1;
      } else if (s[i] == '1' || s[i] == '2'){
        if (s[i] == '2' && s[i+1] - '0' > 6){
          ways[i] = ways[i+1];
        } else {
          if (s[i+1] == '0')
            ways[i] = ways[i+2];
          else
            ways[i] = ways[i+1] + ways[i+2];
        }
      } else {
        ways[i] = ways[i+1];
      }
      //      cout << "->" << ways[i];
    }
    //    cout << endl;
    return ways[0];
  }
};

int main(){
  Solution sol;
  cout << sol.numDecodings("110") << endl;
  cout << sol.numDecodings("") << endl; // 0
  cout << sol.numDecodings("0") << endl; // 0
  cout << sol.numDecodings("123") << endl;
  // 1 2 3; 12 3; 1 23; => 3
  cout << sol.numDecodings("12") << endl; // 2
  cout << sol.numDecodings("12345") << endl;
  // 1 2 3 4 5; 12 3 4 5; 1 23 4 5; => 3
  return 0;
}
