#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) {
      return vector<int>{};
    }
    vector<int> ans(rowIndex + 1, 1);
    int temp1, temp2;
    for (int i = 1; i <= rowIndex; i++) {
      temp1 = 1;
      for (int j = 1; j < i; j++) { // 愚蠢的做法！从后向前 ans[j] = ans[j-1] + ans[j]!
        temp2 = ans[j];
        ans[j] = temp1 + temp2;
        temp1 = temp2;
      }
    }
    return ans;
  }
};

int main() {
  Solution sol;
  int time;
  while (true) {
    cin >> time;
    vector<int> ans = sol.getRow(time);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
      cout << *it << " ";
    }
    cout << endl;
  }
  return 0;
}
