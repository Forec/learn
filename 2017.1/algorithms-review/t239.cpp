#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++){
      if (!dq.empty() && dq.front() == i - k)
        dq.pop_front();
      while (!dq.empty() && nums[dq.back()] < nums[i])
        dq.pop_back();
      dq.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};

int main(){
  vector<int> para = {1,3,-1,-3,5,3,6,7};
  Solution sol;
  vector<int> ans = sol.maxSlidingWindow(para, 3);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
