#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
  void generate(vector<string> &ans, vector<vector<int>> &dp, string tog, int curPos, vector<bool> & visit){
    if (dp[curPos].size() != 0 && dp[curPos][0] == 0 || curPos == 0){
      ans.push_back(tog);
      return;
    }
    if (visit[curPos])
      return;
    //    cout << curPos << " " << visit[curPos] << " " << dp[curPos].size() << endl;
    visit[curPos] = true;
    for (int i = 0; i < dp[curPos].size(); i++){
      tog.insert(tog.begin() + dp[curPos][i], ' ');
      generate(ans, dp, tog, dp[curPos][i], visit);
      tog.erase(tog.begin() + dp[curPos][i]);
    }
    return;
  }
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict;
    for (string word:wordDict){
      dict.insert(word);
    }
    vector<vector<int>> dp(s.length()+1, vector<int>());
    dp[0].push_back(0);
    for (int i = 0; i <= s.length(); i++){
      for (int j = i - 1; j >= 0; j--){
        if (dict.find(s.substr(j, i-j)) != dict.end()){
          for (int vj: dp[j]){
            dp[i].push_back(j);
          }
        }
      }
       // for (int j  = 0; j < dp[i].size(); j++)
       //   cout << dp[i][j] << " ";
      // cout << endl;
    }
    vector<bool> visit(s.length()+1, false);
    vector<string> ans;
    generate(ans, dp, s, s.length(), visit);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<string> dics = {"cat","cats","and","sand","dog"};
  //  vector<string> ans = sol.wordBreak("catsanddog", dics);
  vector<string> dics2 = {"leet", "code", "le", "etc", "ode"};
  //  vector<string> ans2 = sol.wordBreak("leetcode", dics2);
  vector<string> dics3 = {};
  vector<string> ans3 = sol.wordBreak("a", dics3);
  for (string s:ans3){
    cout << s << endl;
  }
  return 0;
}
