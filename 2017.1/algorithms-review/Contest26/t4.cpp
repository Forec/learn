#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../test/quickcheck.h"

using namespace std;


class Solution1 {
public:
  bool splitArray(vector<int>& unums) {
    if (unums.size() < 7)
      return false;
    int tmp = 0;
    int n = unums.size();
    vector<long long> sums(n, 0);
    unordered_map<long long, vector<int>> dict;
    for (int i = 0; i < n; i++){
      tmp += unums[i];
      sums[i] = tmp;
      if (dict.count(tmp)== 0)
        dict[tmp] = vector<int>();
      dict[tmp].push_back(i);
    }
    for (int pos1 = 1; pos1 < n; pos1++){
      int sum = sums[pos1] - unums[pos1];
      if (dict.count(sum + sums[pos1]) == 1){
        vector<int> mayPos2 = dict[sum+sums[pos1]];
        for (int p = 0; p < mayPos2.size(); p++){
          int pos2 = mayPos2[p] + 1;
          if (pos2 < n && dict.count(sum + sums[pos2]) == 1){
            vector<int> mayPos3 = dict[sum+sums[pos2]];
            for (int q = 0; q < mayPos3.size(); q++){
              int pos3 = mayPos3[q] + 1;
              if (pos3 < n && sums[n - 1] - sums[pos3] == sum){
                return true;
              }
            }
          }
        }
      }
    }
    return false;
  }
};


class Solution2 {
private:
  bool check(int start, int end, long long sum, vector<int> & nums){
    int i = start+1, j = end-1;
    long long suml = nums[i], sumr = nums[j];
    while (i < j){
      if (suml < sumr){
        suml += nums[++i];
      } else if (suml > sumr){
        sumr += nums[--j];
      } else if (suml == sumr && j - i == 2){
        if(suml == sum)
          return true;
        return false;
      } else {
        suml += nums[++i];
      }
    }
    return false;
  }
public:
  bool splitArray(vector<int>& nums) {
    if (nums.size() < 7)
      return false;
    int n = nums.size();
    int i = 0, j = n - 1;
    long long suml = nums[i], sumr = nums[j];
    while (i < j){
      if (suml < sumr){
        suml += nums[++i];
      } else if (suml > sumr){
        sumr += nums[--j];
      } else if (suml == sumr){
        if (check(i+1, j-1, suml, nums)){
          return true;
        } else {
          suml += nums[++i];
        }
      }
    }
    return false;
  }
};

class Solution {
public:
  bool splitArray(vector<int>& nums) {
    vector<int> sum(nums.size()+1, 0);
    unordered_set<int> st;
    int sum1, sum2;
    bool ok = false;
    int n = nums.size();
    for (int i = 0; i < n; i++)
      sum[i+1]=sum[i]+nums[i];
    for (int j = 3; j < n-3; j++){
      st.clear();
      for (int i = 1; i+1 < j; i++){
        sum1 = sum[i];
        sum2 = sum[j] - sum[i+1];
        if (sum1 == sum2)
          st.insert(sum1);
      }
      for (int k = j+2; k+1 < n;k++){
        sum1 = sum[k] - sum[j+1];
        sum2 = sum[n] - sum[k+1];
        if (sum1 == sum2)
          if (st.find(sum1) != st.end()){
            ok = true;
            break;
          }
      }
      if (ok) break;
    }
    return ok;
  }
};

int main(){
  Solution sol;
  vector<int> para1 = {-1,0,-1,0,-1,0,-1};
  vector<int> para2 = {1,2,1,2,1,2,1};
  vector<int> para3 = {};
  vector<int> para4 = {1,2,-1,1,2,5,2,5,2};
  cout << (1 ==sol.splitArray(para1)) << endl;
  cout << (1 == sol.splitArray(para2)) << endl;
  cout << (0 == sol.splitArray(para3)) << endl;
  cout << (1 == sol.splitArray(para4)) << endl;
  return 0;
}
