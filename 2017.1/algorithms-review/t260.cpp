#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
      ans ^= nums[i];
    int bit = 1;
    while ((bit & ans) == 0){
      bit <<= 1;
    }
    int num1 = 0, num2 = 0;
    for (int i = 0; i < nums.size(); i++){
      if (nums[i] & bit) {
        num1 ^= nums[i];
      } else {
        num2 ^= nums[i];
      }
    }
    vector<int> res = {num1, num2};
    return res;
  }
};

int main(){
  vector<int> para = {1, 2, 1, 3, 2, 5};
  Solution sol;
  vector<int> ans =sol.singleNumber(para);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
