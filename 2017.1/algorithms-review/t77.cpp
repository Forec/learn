#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
  void generate(vector<vector<int>> &ans, vector<int>& combination, int n, int begin, int k){
    if (combination.size() == k){
      ans.push_back(combination);
      return;
    }
    if (combination.size() > k)
      return;
    for (int i = begin; i <= n; i++){
      combination.push_back(i);
      generate(ans, combination, n, i + 1, k);
      combination.pop_back();
    }
  }
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    if (n <= 0)
      return ans;
    vector<int> combination;
    generate(ans, combination, n, 1, k);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<vector<int>> ans = sol.combine(4, 2);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
