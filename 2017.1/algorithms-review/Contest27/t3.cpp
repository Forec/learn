#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
  int nextGreaterElement(int n) {
    string nums = to_string(n);
    std::next_permutation(nums.begin(), nums.end());
    int nes = atoi(nums.c_str());
    if (nes <= n)
      return -1;
    return nes;
  }
};

int main(){
  Solution sol;
  cout << sol.nextGreaterElement(1) << endl;
  cout << sol.nextGreaterElement(21) << endl; // -1
  cout << sol.nextGreaterElement(12) << endl; // 21
  return 0;
}
