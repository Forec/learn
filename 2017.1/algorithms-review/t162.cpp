#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int findPeakElement(vector<int>& nums){
    if (nums.size() == 1)
      return 0;
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right){
      mid = left + (right - left) / 2;
      if ((mid == 0 && nums[mid] >= nums[mid+1]) ||
          (mid == nums.size() - 1 && nums[mid] >= nums[mid-1]) ||
          (mid != 0 && mid != nums.size() -1 &&
           nums[mid] >= nums[mid-1] && nums[mid] >= nums[mid+1])){
        return mid;
      } else if (mid > 0 && nums[mid-1] > nums[mid]){// left bigger than right
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return mid;
  }
};

// Another wise solution O(n)
// for (int i =1; i < nums.size()-1; i++)
//     if (nums[i] < nums[i-1])
//          return i-1;
// return nums.size() - 1;

int main(){
  Solution sol;
  vector<int> para = {1};
  cout << sol.findPeakElement(para) << endl;
  return 0;
}
