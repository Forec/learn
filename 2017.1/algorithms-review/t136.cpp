#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int i =0; i < nums.size(); i++){
      result ^= nums[i];
    }
    return result;
  }
};

int main() {
  Solution sol;
  vector<int> para = {1, 3, 2, 3, 2, 4, 4};
  cout << sol.singleNumber(para) << endl;
  return 0;
}
