#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size();i ++){
      if (dict.count(nums[i]) == 0){
        dict[nums[i]] = i;
      } else {
        if (i - dict[nums[i]] <= k)
          return true;
        else
          dict[nums[i]] = i;
      }
    }
    return false;
  }
};

int main(){
  Solution sol;
  vector<int> para = {1,4, 2, 3, 1, 4, 5};
  cout << (0 == sol.containsNearbyDuplicate(para, 3)) << endl;
  cout << (1 == sol.containsNearbyDuplicate(para, 4)) << endl;
  return 0;
}
