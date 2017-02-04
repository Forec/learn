#include <iostream>
#include <vector>

using namespace std;

class Solution2{
public:
  int missingNumber(vector<int> & nums){
    int res = 0, i = 0;
    for (i = 0; i < nums.size(); i++)
      res = res ^ i ^ nums[i];
    return res ^ i;
  }
};

class Solution{
public:
  int missingNumber(vector<int> & nums){
    int i, j, temp;
    nums.push_back(-1);
    for (int i = 0; i < nums.size(); i++){
      while (nums[i] >= 0 && nums[i] <= nums.size() && nums[nums[i]] != nums[i]){
        temp = nums[i];
        nums[i] = nums[nums[i]];
        nums[temp] = temp;
      }
    }
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != i)
        return i;
    return nums.size();
  }
};

int main(){
  vector<int> para = {1, 0, 2, 3};
  Solution2 sol;
  cout << sol.missingNumber(para) << endl;
  return 0;
}
