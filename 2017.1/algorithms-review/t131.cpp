#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
private:
  vector<vector<string>> dfs(string s, int firstParaLen){
    if (s.length() == 0){
      return vector<vector<string>>(1, vector<string>());
    }
    for (int i =0; i < firstParaLen / 2; i++){
      if (s[i] != s[firstParaLen - i - 1])
        return vector<vector<string>>();
    }
    string subString = s.substr(firstParaLen);
    string prefix = s.substr(0, firstParaLen);
    vector<vector<string>> res;
    for (int i =1; i <= subString.length(); i++){
      //      cout << firstParaLen << " " << s << " " <<i << " "<< subString<< endl;
      vector<vector<string>> last = dfs(subString, i);
      if (firstParaLen != 0){
        for (int j =0; j < last.size(); j++){
          last[j].insert(last[j].begin(), prefix);
        }
      }
      res.insert(res.begin(), last.begin(), last.end());
    }
    if (res.size() == 0)
      res.push_back(vector<string>(1, s));
    return res;
  }
public:
  vector<vector<string>> partition(string s) {
    return dfs(s, 0);
  }
};

int main(){
  Solution sol;
  vector<vector<string>> part = sol.partition("aab");
  for (int i =0; i < part.size(); i++){
    for (int j = 0; j < part[i].size(); j++){
      cout << part[i][j] << " " ;
    }
    cout << endl;
  }
  return 0;
}
