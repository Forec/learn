#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  int removeDuplicates(vector<int> & nums){
    if (nums.size() == 0)
         return 0;
    int i, j = 0, times = 0;
    for (i = 1 ; i < nums.size(); i++){
      if (nums[i] == nums[j]){
        times++;
        if (times < 2)
          nums[++j] = nums[i];
      } else {
        nums[++j] = nums[i];
        times = 0;
      }
    }
    return j + 1;
  }
};

int main(){
  vector<int> para = {1, 1, 1, 2, 2, 3};
  vector<int> para2 = {};
  Solution sol;
  int ans = sol.removeDuplicates(para);
  for (int i = 0; i < ans; i++){
    cout << para[i] << " ";
  }
  cout << endl;
  return 0;
}
