#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ans;
    for (int i = 0; i < words.size(); i++){
      if (words[i].size() == 0){
        ans.push_back(words[i]);
        continue;
      }
      string fst = words[i].substr(0, 1);
      if (!isalpha(fst[0]))
        continue;
      fst[0] = tolower(fst[0]);
      int index = -1;
      for (int j = 0; j < rows.size(); j++){
        if (rows[j].find(fst) != string::npos){
          index = j;
          break;
        }
      }
      if (index == -1)
        continue;
      bool flag = true;
      for (int j = 1; j < words[i].size(); j++){
        fst = words[i].substr(j, 1);
        if (!isalpha(fst[0]))
          break;
        fst[0] = tolower(fst[0]);
        if (rows[index].find(fst) == string::npos){
          flag = false;
          break;
        }
      }
      if (flag)
        ans.push_back(words[i]);
    }
    return ans;
  }
};


int main(){
  vector<string> para = {"Hello", "Alaska", "Dad", "Peace", "!fjakl", "TAhat", "", "-1", "FaDAF"};
  Solution sol;
  vector<string> ans = sol.findWords(para);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
