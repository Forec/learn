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
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> path;
    vector<string> res;
    dfs(root, ans, path);
    for (int i =0 ; i < ans.size(); i++){
      string curPath = "";
      curPath += to_string(ans[i][0]);
      for (int j = 1; j < ans[i].size(); j++)
        curPath += ("->" + to_string(ans[i][j]));
      res.push_back(curPath);
    }
    return res;
  }
};

int main(){
  TreeNode * root = new TreeNode(4);
  TreeNode * node1 = new TreeNode(6); // 2
  TreeNode * node2 = new TreeNode(5);
  TreeNode * node3 = new TreeNode(1);
  TreeNode * node4 = new TreeNode(3);
  TreeNode * node5 = new TreeNode(2); // 6
  root->left = node1; root->right = node2;
  node1->left = node3; node1->right = node4;
  node2->right = node5;
  Solution sol;
  vector<string> ans = sol.binaryTreePaths(root);
  for (int i =0 ;i < ans.size(); i ++){
      cout << ans[i] << endl ;
  }
  return 0;
}
