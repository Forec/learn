#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2)
      return false;
    int i = 0, j = 1;
    int w = 0;
    unordered_map<int, vector<int>> dict;
    vector<int> zero = {-1};
    dict[0] = zero;
    vector<int> back(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++){
      w += nums[i];
      if (k != 0){
        nums[i] = w % k;
        w = nums[i];
      } else {
        nums[i] = w;
      }
      if (dict.count(w) == 0){
        vector<int> tmp = {i};
        dict[w] = tmp;
      } else {
        dict[w].push_back(i);
      }
    }
    for (int i = 0; i < nums.size();i ++){
      for (int j = 0; j < dict[nums[i]].size(); j++){
        if (dict[nums[i]][j] == i)
          continue;
        if (dict[nums[i]][j] - i > 1 || dict[nums[i]][j] - i < -1)
          return true;
        if ((dict[nums[i]][j] != -1) && ((dict[nums[i]][j] - i == 1 && back[i] == 0) || (dict[nums[i]][j] - i == -1 && back[dict[nums[i]][j]] == 0)))
          return true;
      }
    }
    return false;
  }
};

int main(){
  Solution sol;
  vector<int> para1 = {23, 2, 6, 4, 7};
  vector<int> para2 = {23, 2, 6, 4, 7};
  vector<int> para3=  {0, 0};
  vector<int> para4 = {1, 1};
  cout << sol.checkSubarraySum(para1, -6) << endl;
  cout << sol.checkSubarraySum(para2, 13) << endl;
  cout << sol.checkSubarraySum(para3, 0) << endl;
  cout << sol.checkSubarraySum(para4, 2) << endl;
  return 0;
}
