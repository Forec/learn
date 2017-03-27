#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0;
    int number1 = 0, number2 = 0;
    for (int i = 0; i < nums.size(); i++){
      if (nums[i] == number1)
        count1++;
      else if (nums[i] == number2)
        count2++;
      else if (count1 == 0){
        number1 = nums[i];
        count1 = 1;
      } else if (count2 == 0){
        number2 = nums[i];
        count2 = 1;
      } else {
        count1 --;
        count2 --;
      }
    }
    count1 = count2 = 0;
    for (int i = 0; i < nums.size(); i++){
      if (nums[i] == number1)
        count1++;
      else if (nums[i] == number2)
        count2++;
    }
    vector<int> res;
    if (count1 > nums.size() / 3)
      res.push_back(number1);
    if (count2 > nums.size() / 3)
      res.push_back(number2);
    return res;
  }
};

int main(){
  vector<int> para = {0, 0, 0};
  Solution sol;
  vector<int> ans = sol.majorityElement(para);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
