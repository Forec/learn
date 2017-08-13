#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
private:
  void combine(vector<int> & candidates, int target, vector<vector<int>> & ans, vector<int>& combination, int begin){
    if (!target){
      ans.push_back(combination);
      return;
    }
    for (int i = begin; i < candidates.size() && target >= candidates[i]; i++){
      if (i == begin || candidates[i] != candidates[i-1]){
        combination.push_back(candidates[i]);
        combine(candidates, target - candidates[i], ans, combination, i + 1);
        combination.pop_back();
      }
    }
  }
public:
  vector<vector<int>> combinationSum2(vector<int> & candidates, int target){
    vector<vector<int>> ans;
    vector<int> combination;
    vector<int> canbe;
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i++){
      if (candidates[i] <= target)
        canbe.push_back(candidates[i]);
      else
        break;
    }
    combine(canbe, target, ans, combination, 0);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para = {10, 1, 2, 7, 6, 1, 5};
  vector<vector<int>> ans = sol.combinationSum2(para, 8);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
