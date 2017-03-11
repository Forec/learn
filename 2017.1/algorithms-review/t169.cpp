#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int cnt = 1, major = nums[0];
    for (int i = 1; i < nums.size(); i++){
      if (cnt == 0){
        cnt = 1;
        major = nums[i];
      } else {
        cnt += major == nums[i] ? 1 : -1;
      }
    }
    return major;
  }
};

int main(){
  Solution sol;
  vector<int> para = {1, 2, 3, 1, 1, 2,2,2,2};
  cout << sol.majorityElement(para) << endl;
  return 0;
}
