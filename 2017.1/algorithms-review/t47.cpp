#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
private:
  void generate2(vector<int> &nums, vector<vector<int>> & ans, int k){
    if (k == nums.size()){
      ans.push_back(nums);
      return;
    }
    for (int i = k; i < nums.size(); i++){
      if (i == k || nums[i] != nums[i-1]){
        swap(nums[i], nums[k]);
        generate(nums, ans, k+1);
        swap(nums[i], nums[k]);
      }
    }
  }
  void generate(vector<int> nums, vector<vector<int>> & ans, int k){
    if (k == nums.size()){
      ans.push_back(nums);
      return;
    }
    for (int i = k; i < nums.size(); i++){
      if (i == k || nums[i] != nums[k]){
        swap(nums[i], nums[k]);
        generate(nums, ans, k+1);
      }
    }
  }
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    generate(nums, ans, 0);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para2 = {2, 2, 1, 1};
  vector<int> para = {0, 1, 0, 0, 9};
  vector<vector<int>> ans = sol.permuteUnique(para2);
  cout << ans.size() << endl; // 20
  return 0;
}
