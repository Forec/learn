#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
class Solution{
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long long> window;
    for (int i = 0; i < nums.size(); i++) {
      if (i > k)
        window.erase(nums[i-k-1]);
      auto pos = window.lower_bound((long long)nums[i] - t);
      if (pos != window.end() && *pos - nums[i] <= t) return true;
      window.insert(nums[i]);
    }
    return false;
  }
};

class Solution_fuck {
public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int left = 0, right;
    int n = nums.size();
    if (n <= 1 || k == 0)
      return false;
    if (nums.size()-1 <= k){
      sort(nums.begin(), nums.end());
      for (int i = 0; i < nums.size() - 1; i++){
        if (nums[i+1] - nums[i] <= t)
          return true;
      }
      return false;
    }
    for (int i = 0; i + k < n; i++){
      int end = i + k;
      vector<int> tmp;
      tmp.insert(tmp.begin(), nums.begin() + i, nums.begin() + i + k + 1);
      sort(tmp.begin(), tmp.end());
      for (int i = 1; i <= k; i++){
        if (tmp[i] - tmp[i-1] <= t)
          return true;
      }
    }
    return false;
  }
};

int main(){
  vector<int> para ={100, 20, 40, 50, 3}; // k = 3, t = 10, true
  vector<int> para2 = {0};
  vector<int> para3 = {1, 2};
  vector<int> para4 = {2, 2};
  Solution sol;
  cout << (1==sol.containsNearbyAlmostDuplicate(para, 3, 10)) << endl;
  cout << (0==sol.containsNearbyAlmostDuplicate(para2,0, 0)) << endl;
  cout << (0==sol.containsNearbyAlmostDuplicate(para3,0, 1)) << endl;
  cout << (1==sol.containsNearbyAlmostDuplicate(para4,3, 0)) << endl;
  return 0;
}
