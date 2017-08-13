#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
private:
  void combine(vector<int> &candidates, int target, vector<vector<int>> & ans, vector<int> & combination, int begin){
    if (!target){
      ans.push_back(combination);
      return;
    }
    for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i){
      combination.push_back(candidates[i]);
      combine(candidates, target - candidates[i], ans, combination, i);
      combination.pop_back();
    }
  }
public:
  vector<vector<int>> combinationSum(vector<int> & candidates, int target){
    vector<int> canbe;
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size(); i++){
      if (candidates[i] <= target){
        canbe.push_back(candidates[i]);
      } else {
        break;
      }
    }
    vector<int> combination;
    vector<vector<int>> ans;
    combine(canbe, target, ans, combination, 0);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para = {2, 3, 6, 7};
  vector<vector<int>> ans = sol.combinationSum(para, 7);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
