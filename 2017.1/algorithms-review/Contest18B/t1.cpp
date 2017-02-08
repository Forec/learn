#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < findNums.size(); i++){
      bool find = false;
      for (int j = 0; j < nums.size(); j++){
        if (nums[j] == findNums[i]){
          for (int k = j + 1; k < nums.size(); k++){
            if (nums[k] > findNums[i]){
              ans.push_back(nums[k]);
              find = true;
              break;
            }
          }
          break;
        }
      }
      if (!find)
        ans.push_back(-1);
    }
    return ans;
  }
};
int main(){
  vector<int> para1 = {4, 1, 2};
  vector<int> para2 = {1, 3, 4, 2};
  vector<int> para3 = {2, 4};
  vector<int> para4 = {1, 2, 3, 4};
  Solution sol;
  vector<int> ans1 = sol.nextGreaterElement(para1, para2);
  vector<int> ans2 = sol.nextGreaterElement(para3, para4);
  for (int i = 0; i < ans1.size();i++)
    cout << ans1[i] << " ";
  cout << endl;
  for (int i = 0; i < ans2.size();i++)
    cout << ans2[i] << " ";
  cout << endl;
  return 0;
}
