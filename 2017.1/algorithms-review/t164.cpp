#include <iostream>
#include <vector>
#include "test/quickcheck.h"

using namespace std;

class Solution {
private:
  inline int min(int x,int y){
    return x < y ? x : y;
  }
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2)
      return 0;
    int minNum = nums[0], maxNum = nums[0];
    for (int i = 1; i < nums.size(); i++){
      minNum = min(nums[i], minNum);
      maxNum = max(nums[i], maxNum);
    }
    int gap = ((maxNum - minNum) / (nums.size() -1)) +
      ((maxNum - minNum) % (nums.size() - 1) == 0 ? 0 : 1);
    vector<int> bucketMin(nums.size() -1, INT_MAX);
    vector<int> bucketMax(nums.size() -1, INT_MIN);
    for (int i : nums){
      if (i == minNum || i == maxNum)
        continue;
      int idx = (i - minNum) / gap;
      bucketMin[idx] = min(i, bucketMin[idx]);
      bucketMax[idx] = max(i, bucketMax[idx]);
    }
    int maxGap = INT_MIN;
    int previous = minNum;
    for (int i = 0; i < nums.size() - 1; i++){
      if (bucketMin[i] == INT_MAX && bucketMax[i] == INT_MIN)
        continue;
      maxGap = max(maxGap, bucketMin[i] - previous);
      previous = bucketMax[i];
    }
    maxGap = max(maxGap, maxNum - previous);
    return maxGap;
  }
  int run(VECTOR<int> &v){
    vector<int> para = v.getVEC();
    return maximumGap(para);
  }
};

int main(){
  vector<vector<int>> origins = {{1, 3, 2, 4, 5, 9},
                                 {3, 9, 4, 7, 2, 6}};
  vector<int> ans = {4, 2};
  vector<VECTOR<int>> paras;
  for (int i = 0; i < origins.size(); i++){
    paras.push_back(VECTOR<int>(origins[i]));
  }
  QuickCheck<VECTOR<int>, int, Solution> q(paras, ans);
  q.runTests();
  return 0;
}
