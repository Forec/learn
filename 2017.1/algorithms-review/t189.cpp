#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  void reverse(vector<int> & nums, int left, int right){
    int tmp;
    for (int i = 0; i < (right - left) / 2; i++){
      tmp = nums[left + i];
      nums[left+i] = nums[right-1-i];
      nums[right-1-i] = tmp;
    }
  }
public:
  void rotate(vector<int>& nums, int k) {
    if (nums.size() < 1)
      return;
    k = k % nums.size();
    reverse(nums, 0, nums.size() - k);
    reverse(nums, nums.size() - k, nums.size());
    reverse(nums, 0, nums.size());
  }
};

int main(){
  vector<int> para = {1, 2, 3, 4, 5, 6, 7};
  Solution sol;
  sol.rotate(para, 3);
  for (int i = 0; i < para.size(); i++){
    cout << para[i];
  }
  cout << endl;
  return 0;
}
