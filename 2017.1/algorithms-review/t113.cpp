#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void generatePath(TreeNode* root, int sum, vector<vector<int>> & ans, vector<int> & path) {
    if (root == NULL)
      return;
    if (root->val == sum && root->left == NULL && root->right == NULL){
      path.push_back(root->val);
      ans.push_back(path);
      path.pop_back();
      return;
    }
    path.push_back(root->val);
    if (root->left != NULL)
      generatePath(root->left, sum - root->val, ans, path);
    if (root->right != NULL)
      generatePath(root->right, sum - root->val, ans, path);
    path.pop_back();
  }
public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> path;
    generatePath(root, sum, ans, path);
    return ans;
  }
};

int main(){
  TreeNode * root = new TreeNode(5);
  TreeNode * node1 = new TreeNode(4);
  TreeNode * node2 = new TreeNode(8);
  TreeNode * node3 = new TreeNode(11);
  TreeNode * node4 = new TreeNode(13);
  TreeNode * node5 = new TreeNode(4);
  TreeNode * node6= new TreeNode(7);
  TreeNode * node7= new TreeNode(2);
  TreeNode * node8= new TreeNode(5);
  TreeNode * node9= new TreeNode(1);
  root->left = node1; root->right = node2;
  node1->left = node3; node3->right = node7;
  node3->left = node6; node5->right = node9;
  node5->left = node8;
  node2->left = node4; node2->right = node5;
  vector<vector<int>> ans;
  Solution sol;
  ans = sol.pathSum(root, 22);
  for (int i = 0;i < ans.size(); i++){
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
