#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;
    if (s.length() <= 10)
      return ans;
    unordered_map<string, int> dict;
    for (int i =0; i <= s.length() - 10; i++){
      string subs = s.substr(i, 10);
      if (dict.count(subs) == 0)
        dict[subs] = 0;
      dict[subs] ++;
    }
    for (auto it = dict.begin(); it!=dict.end(); it++){
      if (it->second > 1){
        ans.push_back(it->first);
      }
    }
    return ans;
  }
};

int main(){
  string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
  string s2 = "AAAAAAAAAAA";
  Solution sol;
  vector<string> ans = sol.findRepeatedDnaSequences(s2);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  return 0;
}
