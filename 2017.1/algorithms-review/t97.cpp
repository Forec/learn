#include <iostream>
#include <vector>
#include <string>

#include <algorithm>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length())
      return false;
    int m = s1.length(), n = s2.length();
    vector<vector<bool>> f(m+1, vector<bool>(n+1, false));
    f[0][0] = true;
    for (int i = 1; i <= m; i++)
      f[i][0] = (s1[i-1] == s3[i-1]) && f[i-1][0];
    for (int j = 1; j <= n; j++)
      f[0][j] = (s2[j-1] == s3[j-1]) && f[0][j-1];
    for (int i = 1; i <= m; i++){
      for (int j = 1; j <= n; j++){
        if (s3[i+j-1] == s1[i-1] && f[i-1][j])
          f[i][j] = true;
        if (s3[i+j-1] == s2[j-1] && f[i][j-1])
          f[i][j] = true;
      }
    }
    return f[m][n];
  }
};

int main(){
  Solution sol;
  vector<string> para1 = {"aabcc", "aabcc"};
  vector<string> para2 = {"dbbca", "dbbca"};
  vector<string> para3 = {"aadbbcbcac", "aadbbbaccc"};
  vector<bool> ans = {true, false};
  int failed = 0;
  for (int i = 0; i < ans.size(); i++){
    bool a = sol.isInterleave(para1[i], para2[i], para3[i]);
    if (a != ans[i]){
      failed ++;
      cout << "Failed test case " << i+1 << ", Input: " << para1[i] << ", " << para2[i] << ", " << para3[i] << endl;
      cout << "   Expect " << ans[i] << " got " << a << endl;
    }
  }
  if (failed == 0){
    cout << "Passed all " << ans.size() << " test cases." << endl;
  } else{
    cout << "Passed " << ans.size() - failed<< " test cases, failed " << failed << " test cases" << endl;
  }
  return 0;
}
