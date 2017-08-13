#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool cmpFunc(string s1, string s2){
  if (s1.length() == s2.length())
    return s1 < s2;
  return s1.length() > s2.length();
}

class Solution {
private:
  bool canDelete(string s, string r){
    int i = 0, j = 0;
    while (i < r.length()){
      while (j < s.length() && s[j] != r[i])
        j++;
      if (j == s.length())
        return false;
      if (s[j] == r[i]){
        i++;
        j++;
      }
    }
    return true;
  }
public:
  string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), cmpFunc);
    for (int i = 0; i < d.size(); i++){
      if (canDelete(s, d[i]))
        return d[i];
    }
    return "";
  }
};

int main(){
  Solution sol;
  vector<string> para = {"ale","apple","monkey","plea"};
  vector<string> para2 = {"a","b","c"};
  cout << sol.findLongestWord("abpcplea", para) << endl;
  return 0;
}
