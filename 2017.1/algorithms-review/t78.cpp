#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
private:
  void generate(vector<int> &nums, int start, vector<int> & sub, vector<vector<int>> & subset){
    subset.push_back(sub);
    for (int i = start; i < nums.size(); i++){
      sub.push_back(nums[i]);
      generate(nums, i+1, sub, subset);
      sub.pop_back();
    }
  }
public:
  vector<vector<int>> subsets(vector<int>& S){
    sort(S.begin(), S.end());
    vector<vector<int>> subset;
    vector<int> subsub;
    generate(S, 0, subsub, subset);
    return subset;
  }
  vector<vector<int>> subsets1(vector<int> &S){
    sort(S.begin(), S.end());
    vector<vector<int>> subset(1, vector<int>());
    for (int i = 0; i < S.size(); i++){
      int n = subset.size();
      for (int j = 0; j < n ; j++){
        subset.push_back(subset[j]);
        subset.back().push_back(S[i]);
      }
    }
    return subset;
  }
  vector<vector<int>> subsets2(vector<int> & S){
    sort(S.begin(), S.end());
    int elem_num = S.size();
    int subset_num = pow(2, elem_num);
    vector<vector<int>> subset(subset_num, vector<int>());
    for (int i = 0 ; i < elem_num; i++){
      for (int j = 0; j < subset_num; j++){
        if ((j>>i) & 1)
          subset[j].push_back(S[i]);
      }
    }
    return subset;
  }
};

int main(){
  Solution sol;
  vector<int> para = {1,2,3};
  vector<vector<int>> ans = sol.subsets(para);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
