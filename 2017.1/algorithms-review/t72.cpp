#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2){
    int m = word1.length(), n = word2.length();
    vector<int> F(m+1, 0);
    for (int i = 1; i <= m; i++)
      F[i] = i;
    for (int j = 1; j <= n; j++){
      int last = F[0];
      F[0] = j;
      for (int i = 1; i <= m; i++){
        int tmp = F[i];
        if (word1[i-1] == word2[j-1])
          F[i] = last;
        else
          F[i] = min(last +1, min(F[i]+1, F[i-1] + 1));
        last = tmp;
      }
    }
    return F[m];
  }
};

int main(){
  Solution sol;
  cout << (sol.minDistance("ab","bc")==2) << endl;
  cout << (sol.minDistance("123","321") == 2) << endl;
  cout << (sol.minDistance("a","b") == 1) << endl;
  cout << (sol.minDistance("ab","b") == 1) << endl;
  return 0;
}
