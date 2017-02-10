#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (string word:wordDict){
      dict.insert(word);
    }
    vector<bool> dp(s.length()+1,false);
    dp[0] = true;
    for (int i = 0; i <= s.length(); i++ ){
      for (int j = i - 1; j >= 0; j--){
        if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){
          dp[i] = true;
        }
      }
    }
    return dp[s.length()];
  }
};

int main(){
  Solution sol;
  vector<string> dics = {"leet", "code", "let", "ode"};
  cout << sol.wordBreak("leetcode", dics) << endl; // 1
  return 0;
}
