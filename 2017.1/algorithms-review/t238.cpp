#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int n =nums.size();
    vector<int> res;
    int product = 1;
    for (int i = 0; i < n; i++){
      if (product == 0)
        res.push_back(0);
      else {
        res.push_back(product);
        product *= nums[i];
      }
    }
    product = 1;
    for (int i = n-1; i >= 0; i--){
      if (product == 0){
        res[i] = 0;
      } else {
        res[i] = product * res[i];
        product *= nums[i];
      }
    }
    return res;
  }
};

int main(){
  vector<int> para = {1,2,3,4};
  Solution sol;
  vector<int> ans = sol.productExceptSelf(para);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
