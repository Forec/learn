#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < 32; i++){
      int bitCount = 0;
      for (int j = 0; j < nums.size(); j++){
        if ((nums[j] >> i) & 1)
          bitCount++;
      }
      ans += (nums.size() - bitCount) * bitCount;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para = {4, 14, 2};
  cout << sol.totalHammingDistance(para) << endl;
  return 0;
}
