#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    int i = 0, j = 1;
    int minumum = nums.size(), sum = nums[0], subsum = nums[0];
    while (j <= nums.size()){
      while (j <= nums.size() && i <= j){
        //        cout << i << " " << j << " " << subsum << " " << sum << " " << minumum<<endl;
        if (subsum < s){
          if (j == nums.size()){
            j++;
            break;
          }
          sum += nums[j];
          subsum += nums[j++];
        } else {
          if (j - i < minumum){
            minumum = j - i;
          }
          subsum -= nums[i++];
        }
      }
    }
    return sum < s ? 0 : minumum;
  }
};

int main(){
  vector<int> para = {5,1,3,5,10,7,4,9,2,8};
  vector<int> para2 = {2,3,1,2,4,3};
  vector<int> para3 = {1, 4, 4};
  vector<int> para4 = {1, 2, 3, 4, 5};
  Solution sol;
  cout << (2 == sol.minSubArrayLen(15, para)) << endl;
  cout << (2 == sol.minSubArrayLen(7, para2)) << endl;
  cout << (1 == sol.minSubArrayLen(4, para3)) << endl;
  cout << (5 == sol.minSubArrayLen(15, para4)) << endl;
  return 0;
}
