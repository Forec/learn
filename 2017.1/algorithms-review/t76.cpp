#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
  bool verify(unordered_map<char, int> & need, unordered_map<char, int>  &dict){
    for (unordered_map<char, int>::iterator it = need.begin(); it!= need.end(); it++){
      if (dict[it->first] < it->second){
        return false;
      }
    }
    return true;
  }
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> need, dict;
    if (t.length() == 0)
      return "";
    for (int i = 0; i < t.length(); i++){
      if (need.count(t[i]) == 0){
        need[t[i]] = 0;
        dict[t[i]] = 0;
      }
      need[t[i]] ++;
    }
    int i = 0, j =0;
    int minLength = s.length() + 1;
    string ans = "";
    bool satisfy = false;
    while (j <= s.length()){
      if (satisfy){
        while (i < j && need.count(s[i]) == 0)
          i++;
        if (minLength > j - i){
          minLength = j - i;
          ans = s.substr(i, j - i);
        }
        dict[s[i]] --;
        i++;
      } else {
        while (j < s.length() && need.count(s[j]) == 0)
          j++;
        if (j == s.length())
          break;
        dict[s[j]] ++;
        j++;
      }
      satisfy = verify(need, dict);
    }
    return ans;
  }
};

int main(){
  string a = "ADOBECODEBANC";
  string b = "ABC";
  Solution sol;
  cout << sol.minWindow(a, b) << endl;
  return 0;
}
