#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Solution {
public:
  string optimalDivision(vector<int>& nums) {
    if (nums.size() == 1)
      return to_string(nums[0]);
    if (nums.size() == 2)
      return to_string(nums[0]) + "/" + to_string(nums[1]);
    string div = to_string(nums[1]);
    for (int i = 2; i < nums.size(); i++)
      div += ("/" + to_string(nums[i]));
    return to_string(nums[0]) + "/(" + div + ")";
  }
};

int main(){
  Solution sol;
  vector<int> para = {1000,100,10,2};
  vector<int> para2 = {5, 4, 2, 2};
  vector<int> para3 = {6, 2, 3, 4, 5};
  vector<int> para4 = {3, 4, 5};
  //  cout << sol.optimalDivision(para) << endl;
  //  cout << sol.optimalDivision(para2) << endl;
  cout << sol.optimalDivision(para3) << endl;
  cout << sol.optimalDivision(para4) << endl;
  return 0;
}
