#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int i = 0, j = 0;
    while (j < nums.size()){
      if (nums[j] != 0){
        nums[i] = nums[j];
        i++;
      }
      j++;
    }
    while (i < nums.size())
      nums[i++] = 0;
  }
};

int main(){
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution sol;
  sol.moveZeroes(nums);
  for (auto t : nums){
    cout << t << " ";
  }
  cout << endl;
  return 0;
}
