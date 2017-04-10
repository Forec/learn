#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums){
    int slow = 0, fast = 0;
    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }while (slow != fast);
    fast = 0;
    do {
      slow = nums[slow];
      fast = nums[fast];
    } while (slow != fast);
    return slow;
  }
};

class Solution2 {
public:
  int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right - 1){
      // 1 2 2 3 4 5
      // 0 1 2 3 4 5  mid = 2
      //      cout << left << " " << right << endl;
      int mid = left + (right - left) / 2;
      if (nums[right] - nums[mid] < right - mid)
        left = mid;
      else if (nums[mid] - nums[left] < mid - left)
        right = mid;
      else {
        int x = nums[mid];
        if (mid > 0 && nums[mid-1] == x || mid < n-1 && x == nums[mid+1])
          return x;
        else
          right = mid - 1;
      }
    }
    return nums[left];
  }
};

int main(){
  vector<int> para = {1, 1, 2};
  Solution sol;
  cout << sol.findDuplicate(para) << endl;
  return 0;
}
