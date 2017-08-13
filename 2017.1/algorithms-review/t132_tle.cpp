#include <iostream>
#include <vector>
#include <string>
#include "test/quickcheck.h"

using namespace std;

class Solution_TLE {
public:
  int minCut(string s) {
    int m = s.length();
    vector<vector<int>> f(m, vector<int>(m, 0));
    for (int k = 2; k <= m; k++){
      for (int i = 0; i <= m - k; i++){
        int j = i + k - 1;
        int qual = i, quar = j;
        bool isPalindrome = true;
        if (s[i] == s[j] && f[i+1][j-1] == 0){
          f[i][j] = 0;
          continue;
        }
        while (qual < quar){
          if (s[qual] != s[quar])
            isPalindrome = false;
          qual++; quar--;
        }
        int minC = 0;
        if (!isPalindrome){
          minC = j - i;
          for (int p = i; p < j; p++){
            if (f[i][p] + f[p+1][j] + 1 < minC)
              minC = f[i][p] + f[p+1][j] + 1;
          }
        }
        f[i][j] = minC;
      }
    }
    return f[0][m-1];
  }
  int run(string s){
    return minCut(s);
  }
};

int main(){
  Solution sol;
  vector<string> ins = {"aab", "cdd"};
  vector<int> ans = {1, 1};
  QuickCheck<string, int, Solution> * q= new QuickCheck<string, int, Solution>(ins, ans);
  q->runTests();
  return 0;
}
