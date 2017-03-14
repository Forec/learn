#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);
    vector<int> f(nums.size(), 0);
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++){
      f[i] = max(f[i-1], f[i-2] + nums[i]);
    }
    return f[nums.size()-1];
  }
};

int main(){
  vector<int> robs = {4, 3, 5, 9, 4, 0};
  Solution sol;
  cout << sol.rob(robs) << endl; // 4+5+4 = 13
  return 0;
}
