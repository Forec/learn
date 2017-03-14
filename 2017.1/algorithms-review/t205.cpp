#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> dict1;
    unordered_map<char, char> dict2;
    if (s.length() != t.length())
      return false;
    for (int i =0; i < s.length(); i++){
      if (dict1.count(s[i]) == 0 && dict2.count(t[i]) == 0){
        dict1[s[i]] = t[i];
        dict2[t[i]] = s[i];
      } else{
        if (dict1[s[i]] != t[i] || dict2[t[i]] != s[i])
          return false;
        dict1[s[i]] = t[i];
        dict2[t[i]] = s[i];
      }
    }
    return true;
  }
};

int main(){
  Solution sol;
  cout << (sol.isIsomorphic("egg", "add") == 1) << endl;
  cout << (sol.isIsomorphic("foo", "bar") == 0) << endl;
  cout << (sol.isIsomorphic("paper", "title") == 1) << endl;
  return 0;
}
