#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<int> scores(nums);
    sort(scores.begin(), scores.end());
    map<int, int> dict;
    for (int i = 0; i < scores.size(); i++)
      dict[scores[i]] = nums.size() - i;
    vector<string> ans;
    for (int i = 0; i < nums.size(); i++){
      if (dict[nums[i]] == 1)
        ans.push_back("Gold Medal");
      else if (dict[nums[i]] == 2)
        ans.push_back("Silver Medal");
      else if (dict[nums[i]] == 3)
        ans.push_back("Bronze Medal");
      else
        ans.push_back(to_string(dict[nums[i]]));
    }
    return ans;
  }
};

int main(){
  vector<int> nums1 = {5, 4, 3, 2, 1, 6, 7, 0};
  Solution sol;
  vector<string> ans1 = sol.findRelativeRanks(nums1);
  for (int i = 0; i < ans1.size(); i++)
    cout << ans1[i] << " ";
  cout << endl;
  return 0;
}
