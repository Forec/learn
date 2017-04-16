#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
private:
  int mod = 1000000007;
  int f[100001][2][3];
  void inc(int &x, int y){
    x += y;
    if (x >= mod)
      x -= mod;
  }
public:
  int checkRecord(int n) {
    f[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
      for (int j = 0; j <= 1; j++){
        for (int k = 0; k <= 2; k++){
          int w = f[i-1][j][k];
          if (!w)
            continue;
          if (j == 0)
            inc(f[i][1][0], w);
          if (k < 2)
            inc(f[i][j][k+1], w);
          inc(f[i][j][0], w);
        }
      }
    }
    int res = 0;
    for (int i = 0; i <= 1; i++)
      for (int j = 0; j <= 2; j++)
        inc(res, f[n][i][j]);
    return res;
  }
};

int main(){
  Solution sol;
  cout << sol.checkRecord(2) << endl;
  return 0;
}
