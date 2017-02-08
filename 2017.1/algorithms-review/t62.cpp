#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int uniquePaths(int m, int n) {
    if (m <= 0 || n <= 0)
      return 0;
    if (m <= 1 || n <= 1)
      return 1;
    vector<int> pre(n, 1);
    vector<int> cur(n, 0);
    cur[0] = 1;
    for (int j = 1; j < m; j++){
      for (int i = 1; i < n; i++){
        cur[i] = cur[i-1] + pre[i];
        pre[i] = cur[i];
      }
    }
    return cur[n-1];
  }
};

int main(){
  Solution sol;
  cout << sol.uniquePaths(2, 2) << endl;
  return 0;
}
