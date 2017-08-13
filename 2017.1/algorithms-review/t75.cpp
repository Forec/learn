#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int low = 0, high = nums.size()-1, mid = 0, tmp;
    while (mid <= high){
      if (nums[mid] == 0){
        tmp = nums[mid];
        nums[mid] = nums[low];
        nums[low] = tmp;
        low++;
        mid++;
      } else if (nums[mid] == 1){
        mid++;
      } else if (nums[mid] == 2){
        tmp = nums[high];
        nums[high] = nums[mid];
        nums[mid] = tmp;
        high--;
      }
    }
  }
};

int main(){
  vector<int> para = {0, 2, 1, 0, 1, 1, 0, 0, 2, 0, 1, 0};
  Solution sol;
  sol.sortColors(para);
  for (int i=0; i < para.size(); i++){
    cout << para[i] << endl;
  }
  return 0;
}
