#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void dfs(TreeNode* root, vector<vector<int>> & ans, vector<int> path){
    if (!root) return;
    path.push_back(root->val);
    if (!root->left && !root->right){
      ans.push_back(path);
      return;
    }
    if (root->left)
      dfs(root->left, ans, path);
    if (root->right)
      dfs(root->right, ans, path);
    path.pop_back();
  }
public:
  int sumNumbers(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> path;
    int res = 0;
    dfs(root, ans, path);
    for (int i =0 ; i < ans.size(); i++){
      int sum = 0;
      for (int j = 0; j < ans[i].size(); j++){
        sum *= 10;
        sum += ans[i][j];
      }
      res += sum;
    }
    return res;
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  root->left = node1; root->right = node2;
  Solution sol;
  cout<< sol.sumNumbers(root) << endl;
  return 0;
}
