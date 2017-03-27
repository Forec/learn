#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans;
    if (nums.size() == 0)
      return ans;
    int preValue = nums[0], lastValue = nums[0];
    for (int i = 1; i < nums.size(); i++){
      if (nums[i] - lastValue != 1){
        if (preValue != lastValue)
          ans.push_back(to_string(preValue) + "->" + to_string(lastValue));
        else
          ans.push_back(to_string(preValue));
        preValue = nums[i];
      }
      lastValue = nums[i];
    }
    if (preValue == lastValue)
      ans.push_back(to_string(preValue));
    else
      ans.push_back(to_string(preValue) + "->" + to_string(lastValue));
    return ans;
  }
};

int main(){
  vector<int> para = {0, 2, 3, 5};
  Solution sol;
  vector<string> ans = sol.summaryRanges(para);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
