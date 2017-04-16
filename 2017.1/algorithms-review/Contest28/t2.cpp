#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
  string reverseString(string s){
    reverse(s.begin(), s.end());
    return s;
  }
  string generate(vector<string>& strs, int index, int st, bool reversed){
    string res = "";
    string first = strs[index];
    if (reversed)
      reverse(first.begin(), first.end());
    for (int j = st; j < first.size(); j++)
      res.push_back(first[j]);
    for (int i = (index+1) % strs.size(); i != index; i= (i+1) % strs.size())
      res += max(strs[i], reverseString(strs[i]));
    for (int j = 0; j < st; j++)
      res.push_back(first[j]);
    return res;
  }
public:
  string splitLoopedString(vector<string>& strs) {
    string res = generate(strs, 0, 0, false);
    for (int i = 0; i < strs.size(); i++)
      for (int j = 0; j < strs[i].size(); j++)
        for (bool b: {true, false})
          res = max(res, generate(strs, i, j, b));
    return res;
  }
};

int main(){
  Solution sol;
  vector<string> para = {"abc", "xyz"};
  cout << sol.splitLoopedString(para) << endl;
  return 0;
}
