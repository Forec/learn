#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
  vector<int> sums;
public:
  NumArray(vector<int> nums) {
    sums.resize(nums.size() + 1, 0);
    sums[0] = 0;
    for (int i = 1; i <= nums.size(); i++) {
      sums[i] = sums[i-1] + nums[i-1];
    }
  }
  int sumRange(int i, int j) {
    return sums[j+1] - sums[i];
  }
};

int main(){
  vector<int> para = {-2, 0, 3, -5, 2, -1};
  NumArray arr(para);
  cout << arr.sumRange(0, 2) <<endl;
  cout << arr.sumRange(2, 5) <<endl;
  cout << arr.sumRange(0, 5) <<endl;
  return 0;
}
