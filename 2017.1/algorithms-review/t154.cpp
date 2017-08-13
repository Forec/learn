#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int findMin(vector<int>&nums){
    if (nums.size() == 0)
      return 0;
    else if (nums.size() == 1)
      return nums[0];
    else if (nums.size() == 2)
      return min(nums[0], nums[1]);
    int left = 0, right = nums.size() - 1;
    while (left < right - 1){
      if (nums[left] < nums[right])
        return nums[left];
      int mid = left + (right - left) / 2;
      if (nums[mid] > nums[left])
        left = mid;
      else if (nums[mid] < nums[left])
        right = mid;
      else
        left ++;
    }
    return min(nums[left], nums[right]);
  }
};

int main(){
  Solution sol;
  vector<int> para = {4, 4, 4, 5, 6, 7, 0, 1, 2, 3};
  cout << sol.findMin(para) << endl;
  return 0;
}
