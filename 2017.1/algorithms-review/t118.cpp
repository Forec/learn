#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    if (numRows <= 0)
      return ans;
    ans.push_back(vector<int>{1});
    if (numRows == 1)
      return ans;
    vector<int> pre(1, 1);
    for (int i = 2; i <= numRows; i++) {
      vector<int> temp(1, 1);
      for (int j = 1; j < i - 1; j++) {
        temp.push_back(pre[j] + pre[j - 1]);
      }
      temp.push_back(1);
      pre = temp;
      ans.push_back(temp);
      temp.clear();
    }
    return ans;
  }
};

int main() {
  Solution sol;
  int time;
  while(true) {
    cin >> time;
    vector<vector<int>> ans = sol.generate(time);
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
