#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int removeBoxes(vector<int>& boxes) {
    vector<int> color = {0}, len = {0};
    int dp[101][101][101];
    bool vis[101];
    if (boxes.size() == 0)
      return 0;
    int pre = boxes[0], prei = 0;
    for (int i = 1; i < boxes.size(); i++){
      if (pre != boxes[i]){
        color.push_back(pre);
        len.push_back(i - prei);
        pre = boxes[i];
        prei = i;
      }
    }
    color.push_back(pre);
    len.push_back(boxes.size() - prei);

    int m = color.size(), n = boxes.size();
    vector<int> after(m, 0);
    memset(vis, false, sizeof(vis));

		for(int i = m - 1; i >= 2; i--){
      if(vis[i])
        continue;
			int tmp = i;
			for(int j = i - 1; j >= 1; j--)
				if(color[j] == color[tmp]){
					after[j] = after[tmp] + len[tmp];
					tmp = j;
					vis[j] = true;
				}
		}

		memset(dp, 0, sizeof(dp));
		for(int j = 1; j < m; j++){
			for(int l = 1; l+j-1 < m; l++){
				int r = l+j-1;
				for(int k = 0; k <= after[r]; k++){
					dp[l][r][k] = dp[l][r-1][0] + (len[r]+k) * (len[r]+k);
					for(int p = r - 2; p >= l; p--)
						if(color[p] == color[r])
							dp[l][r][k] = max(dp[l][r][k], dp[l][p][k+len[r]]+dp[p+1][r-1][0]);
				}
			}
		}
    return dp[1][m-1][0];
  }
};

int main(){
  Solution sol;
  vector<int> para = {1, 3, 2, 2, 2, 3, 4, 3, 1}; // 23
  cout << sol.removeBoxes(para) << endl;
  vector<int> para2 = {1, 2, 2, 3, 1, 2, 2}; // 19
  cout << sol.removeBoxes(para2) << endl;
  vector<int> para3 = {4}; // 1
  cout << sol.removeBoxes(para3) << endl;
  vector<int> para4 = {2, 5, 2}; // 5
  cout  << sol.removeBoxes(para4) << endl;
  return 0;
}
