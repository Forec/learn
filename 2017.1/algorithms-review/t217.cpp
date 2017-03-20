#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return !(nums.size() == s.size());
  }
};

int main(){
  Solution sol;
  vector<int> para = {1, 34, 2, 4, 1};
  cout << sol.containsDuplicate(para) <<  endl;
  return 0;
}
