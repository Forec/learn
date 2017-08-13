#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int i = 0, step = 0, cur = 0, next = 0;
    while ( i < nums.size()){
      if (cur >= nums.size() - 1)
        break;
      while (i <= cur){
        next = max(next, nums[i] + i);
        i ++;
      }
      step++;
      cur = next;
    }
    return step;
  }
};

int main(){
  Solution sol;
  vector<int> para2 = {2, 3, 1, 1, 4};
  vector<int> para = {3, 2, 1, 0, 4};
  int ans1 = sol.jump(para), ans2 = sol.jump(para2);
  cout << ans1 << " " << ans2 << endl; // 0 1
  return 0;
}
