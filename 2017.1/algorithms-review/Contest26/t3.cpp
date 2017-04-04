#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../test/quickcheck.h"

using namespace std;

class Solution {
private:
  vector<bool> visited;
  int n;
  void dfs(vector<vector<int>> &M, int u){
    visited[u] = true;
    for (int i = 0; i < n; i++){
      if (M[u][i] && visited[i] == false)
        dfs(M, i);
    }
  }
public:
  int findCircleNum(vector<vector<int>>& M) {
    if (M.size() == 0 || M[0].size() == 0)
      return 0;
    n = M.size();
    visited.resize(n, false);
    for (int i = 0; i < n; i++)
      visited[i] = false;
    int count = 0;
    for (int i =0; i < n; i ++){
      if (visited[i] == false){
        dfs(M, i);
        count++;
      }
    }
    return count;
  }
};

int main(){
  Solution sol;
  vector<vector<int>> para1 = {{1,1,0},
                               {1,1,0},
                               {0,0,1}};
  vector<vector<int>> para2 = {{1,1,0},
                               {1,1,1},
                               {0,1,1}};
  cout << sol.findCircleNum(para1) << endl;
  cout << sol.findCircleNum(para2) << endl;
  return 0;
}
