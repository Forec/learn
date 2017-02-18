#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> dict;
    vector<vector<string>> ans;
    for (vector<string>::iterator it = strs.begin(); it != strs.end();it++){
      string tmp = *it;
      sort(tmp.begin(), tmp.end());
      if (dict.count(tmp) == 0){
        vector<string> empty;
        dict[tmp] = empty;
      }
      dict[tmp].push_back(*it);
    }
    unordered_set<string> inputed;
    for (vector<string>::iterator it = strs.begin(); it != strs.end(); it++){
      string tmp = *it;
      sort(tmp.begin(), tmp.end());
      if (dict.count(tmp) >= 1 && inputed.count(tmp) == 0){
        sort(dict[tmp].begin(), dict[tmp].end());
        ans.push_back(dict[tmp]);
        inputed.insert(tmp);
      }
    }
    return ans;
  }
};


int main(){
  vector<string> para = {"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution sol;
  vector<vector<string>> ans = sol.groupAnagrams(para);
  for (vector<vector<string>>::iterator it = ans.begin(); it != ans.end(); it++){
    for (vector<string>::iterator _it = it->begin(); _it != it->end(); _it++){
      cout << *_it << " ";
    }
    cout << endl;
  }
  return 0;
}
