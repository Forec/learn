#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  int divide(vector<int>& nums, int left, int right){
    if (left >= right)
      return INT_MIN;
    if (left == right - 1)
      return nums[left];
    int mid = left + ((right - left) >> 1);
    int lmax = divide(nums, left, mid);
    int rmax = divide(nums, mid+1, right);
    int tmax = max(lmax, rmax);
    int sum = 0, lsmax = 0, rsmax = 0;
    for (int i = mid -1; i>= left; i--){
      sum += nums[i];
      lsmax = max(lsmax, sum);
    }
    sum = 0;
    for (int i = mid + 1; i < right; i++){
      sum += nums[i];
      rsmax = max(rsmax, sum);
    }
    return max(tmax, lsmax + rsmax + nums[mid]);
  }
public:
  int maxSubArray2(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    int sum = 0, maxm = INT_MIN;
    for(int i = 0; i < nums.size(); i++){
      sum += nums[i];
      maxm = max(maxm, sum);
      sum = max(0, sum);
    }
    return maxm;
  }
  int maxSubArray(vector<int> &nums){
    if (nums.size() == 0)
      return 0;
    return divide(nums, 0, nums.size());
  }
};

int main(){
  vector<int> para = {-2,1,-3,4,-1,2,1,-5,4};
  vector<int> para2 = {-1};
  Solution sol;
  cout << sol.maxSubArray(para) << endl;
  return 0;
}
