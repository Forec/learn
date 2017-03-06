#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> ans = {0};
    int base = 1;
    for (int i = 1; i <= n; i++){
      int preSize = ans.size();
      int tmp;
      for (int j = preSize - 1; j >= 0; j--){
        tmp = ans[j];
        tmp |= base;
        ans.push_back(tmp);
      }
      base <<= 1;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> ans = sol.grayCode(2);
  cout << (ans.size()== 4 && ans[0]==0 && ans[1] == 1 && ans[2] == 3 && ans[3] == 2) << endl;
  vector<int> ans2 = sol.grayCode(1);
  cout << (ans2.size()== 2 && ans2[0]==0 && ans2[1] == 1) << endl;
  return 0;
}
