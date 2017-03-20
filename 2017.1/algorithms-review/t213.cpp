#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int rob(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];
    if (nums.size() == 2)
      return max(nums[0], nums[1]);
    vector<int> f(nums.size(), 0);
    int result = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++){
      vector<int> current;
      current.insert(current.end(), nums.begin() + i + 1, nums.end());
      current.insert(current.end(), nums.begin(), nums.begin() + i);
      f[0] = current[0];
      f[1] = max(current[0], current[1]);
      for (int j = 2; j < n-1 ; j++){
        f[j] = max(f[j-1], f[j-2] + current[j]);
      }
      result = max(result, f[n-2]);
    }
    return result;
  }
};

int main(){
  vector<int> para1 = {4, 2, 5, 2, 9}; // 5 9 => 14
  vector<int> para2 = {9, 9, 9, 9, 9, 9, 1, 2, 3, 100, 1, 2}; // 131
  //      4
  //   2     9
  //     5 2
  Solution sol;
  cout << sol.rob(para2) << endl;
  return 0;
}
