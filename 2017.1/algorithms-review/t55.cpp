#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int i = 0;
    for (int reach = 0; i <= reach && i < nums.size(); i++){
      reach = max(i + nums[i], reach);
    }
    return i == nums.size();
  }
};

int main(){
  Solution sol;
  vector<int> para2 = {2, 3, 1, 1, 4};
  vector<int> para = {3, 2, 1, 0, 4};
  int ans1 = sol.canJump(para), ans2 = sol.canJump(para2);
  cout << ans1 << " " << ans2 << endl; // 0 1
  return 0;
}
