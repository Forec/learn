#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0)
      return 0;
    int best = nums[0];
    int maxP = nums[0], minP = nums[0];
    for (int i = 1; i < nums.size(); i++){
      int tmp = minP;
      minP = min(minP * nums[i], min(maxP * nums[i], nums[i]));
      maxP = max(maxP * nums[i], max(tmp * nums[i], nums[i]));
      best = max(maxP, best);
    }
    return best;
  }
};

int main(){
  vector<int> para = {7, -1, 5}; 
  vector<int> para2 = {7, 6, 4, 3, 1};
  Solution sol;
  cout << sol.maxProduct(para) <<endl;
  return 0;
}
