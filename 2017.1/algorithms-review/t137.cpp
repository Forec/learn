#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int first = 0, second = 0;
    for (int i = 0; i < nums.size(); i++){
      first = (first ^ nums[i]) & (~ second);
      second = (second ^ nums[i]) & (~first);
    }
    return first;
  }
};

// a more general way : https://discuss.leetcode.com/topic/22821/an-general-way-to-handle-all-this-sort-of-questions/2

// 1 -> first = 0, second = 0 => first = x, second = 0
// 2 -> first = x, second = 0 => first = 0, second = x
// 3 -> first = 0, second = x => first = 0, second = 0

int main(){
  vector<int> para = {1, 2, 1, 1, 3, 3, 2, 3, 2, 4};
  Solution sol;
  cout << sol.singleNumber(para) << endl;
  return 0;
}
