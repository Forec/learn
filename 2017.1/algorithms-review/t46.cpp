#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
private:
  void generate(vector<int> &nums, vector<vector<int>> & ans, int k){
    if (k == nums.size()){
      ans.push_back(nums);
      return;
    }
    for (int i = k; i < nums.size(); i++){
      //      if (i == k || nums[i] != nums[i-1]){
        swap(nums[i], nums[k]);
        generate(nums, ans, k+1);
        swap(nums[i], nums[k]);
        //      }
    }
  }
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    generate(nums, ans, 0);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para = {1,2,2};
  vector<vector<int>> ans = sol.permute(para);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
