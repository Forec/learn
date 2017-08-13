#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
  int trap(vector<int>& height) {
    int ans = 0;
    int left = 0, right = height.size()-1;
    int maxLeft = 0, maxRight = 0;
    while (left <= right){
      if (height[left] <= height[right]){
        if (height[left] >= maxLeft)
          maxLeft = height[left];
        else
          ans += maxLeft - height[left];
        left++;
      } else {
        if (height[right] >= maxRight)
          maxRight = height[right];
        else
          ans += maxRight - height[right];
        right--;
      }
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << sol.trap(para) << endl;
  return 0;
}
