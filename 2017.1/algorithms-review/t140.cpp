#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


// this solution is from https://discuss.leetcode.com/topic/12997/11ms-c-solution-concise
// using memorized search
class Solution2 {
  unordered_map<string, vector<string>> m;

  vector<string> combine(string word, vector<string> prev){
    for(int i=0;i<prev.size();++i){
      prev[i]+=" "+word;
    }
    return prev;
  }

public:
  vector<string> wordBreak(string s, unordered_set<string>& dict) {
    if(m.count(s)) return m[s]; //take from memory
    vector<string> result;
    if(dict.count(s)){ //a whole string is a word
      result.push_back(s);
    }
    for(int i=1;i<s.size();++i){
      string word=s.substr(i);
      if(dict.count(word)){
        string rem=s.substr(0,i);
        vector<string> prev=combine(word,wordBreak(rem,dict));
        result.insert(result.end(),prev.begin(), prev.end());
      }
    }
    m[s]=result; //memorize
    return result;
  }
};

class Solution {
private:
  vector<vector<char>> dp;
  vector<string> vals;
  string val;
  void dfs(const string &s, int start){
    int len = s.length();
    if (start == len){
      vals.push_back(val);
      return;
    }
    for (int i = 1; i <= len-start; i++){
      if (dp[start][i] == 1){
        int oldLen = val.length();
        if (oldLen != 0){
          val.append(" ");
        }
        val.append(s.substr(start, i));
        dfs(s, start+i);
        val.erase(oldLen, string::npos);
      }
    }
  }
public:
  vector<string> wordBreak(string s, vector<string> wordDict){
    unordered_set<string> dict;
    for (string word:wordDict){
      dict.insert(word);
    }
    int len = s.length();
    dp.resize(len, vector<char>(len+1, 0));
    for (int i = 1;i <= len; i++){
      for (int j = 0; j < len - i + 1; j++){
        if (dict.find(s.substr(j, i)) != dict.end()){
          dp[j][i] = 1;
          continue;
        }
        for (int k = 1; k < i && k < len - j; k++){
          if (dp[j][k] && dp[j+k][i-k]){
            dp[j][i] = 2;
            break;
          }
        }
      }
    }
    if (dp[0][len] != 0){
      dfs(s, 0);
    }
    return vals;
  }
};

int main(){
  Solution sol;
  vector<string> dics = {"cat","cats","and","sand","dog"};
    vector<string> ans = sol.wordBreak("catsanddog", dics);
  vector<string> dics2 = {"leet", "code", "le", "etc", "ode"};
    vector<string> ans2 = sol.wordBreak("leetcode", dics2);
  vector<string> dics3 = {};
  vector<string> ans3 = sol.wordBreak("a", dics3);
  for (string s:ans){
    cout << s << endl;
  }
  return 0;
}
