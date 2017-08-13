#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    vector<int> bigger(n, -1);
    for (int i = 0; i < n; i++){
      int k = (i + 1)%n;
      int count = 0;
      while (k != i && count < n){
        count++;
        if (nums[k] > nums[i])
          break;
        if (nums[k] < nums[i] && bigger[k] != -1){
          k = (k + bigger[k]) % n;
        } else {
          k = (k+1) % n;
        }
      }
      if (k == i || count == n)
        ans.push_back(-1);
      else{
        ans.push_back(nums[k]);
        bigger[i] = (k - i)%n;
      }
    }
    return ans;
  }
};

int main(){
  vector<int> para1 = {1, 2, 1, 4, 2, 3, 1, 4, 5};
  Solution sol;
  vector<int> ans = sol.nextGreaterElements(para1);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout <<endl;
  return 0;
}
