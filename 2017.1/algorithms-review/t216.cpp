#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
  int numbers;
  void combine(vector<vector<int>> & ans, int target, int begin, vector<int>& combination, int left){
    if (!target){
      ans.push_back(combination);
      return;
    } else if (!left)
      return;
    for (int i = begin; i <= 9 && target >= i * left + left * (left - 1) / 2; i ++){
      combination.push_back(i);
      combine(ans, target - i, i + 1, combination, left - 1);
      combination.pop_back();
    }
  }
public:
  vector<vector<int>> combinationSum3(int k, int n){
    vector<int> combination;
    vector<vector<int>> ans;
    combine(ans, n, 1, combination, k);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<vector<int>> ans = sol.combinationSum3(3, 7);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
