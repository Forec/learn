#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.length(), n = t.length();
    vector<vector<int>> f(m+1, vector<int>(n+1, 0));
    f[0][0] = 1;
    for (int j = 1; j <= n; j++){
      for (int i = 1; i <= m; i++){
        if (s[i-1] == t[j-1]){
          int sum = 0;
          for (int k = 0; k < i; k++)
            sum += f[k][j-1];
          f[i][j] = sum;
        }
      }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++){
      ans += f[i][n];
    }
    return ans;
  }
};

int main(){
  vector<string> paraS = {"rabbbit"};
  vector<string> paraT = {"rabbit"};
  vector<int> ans = {3};
  Solution sol;
  int failed = 0;
  for (int i = 0; i < ans.size(); i++){
    int a = sol.numDistinct(paraS[i], paraT[i]);
    if (a != ans[i]){
      failed ++;
      cout << "Failed test " << i+1 << ": Input: \"" << paraS[i]<< "\", \"" << paraT[i] << "\"" << endl;
      cout << "       Expected: " << ans[i] << ", actual: " << a << endl;
    }
  }
  if (failed == 0){
    cout << "Passed all " << ans.size() << " tests" << endl;
  } else {
    cout << "Passed " << ans.size() - failed << " test cases, failed " << failed << " test cases." << endl;
  }
  return 0;
}
