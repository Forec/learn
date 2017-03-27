#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
      return NULL;
    TreeNode * right = root->right;
    root->right = invertTree(root->left);
    root->left = invertTree(right);
    return root;
  }
  void dfs(TreeNode * root){
    if (root == NULL)
      return;
    cout << root->val << " " ;
    dfs(root->left);
    dfs(root->right);
  }
};

int main(){
  TreeNode * n4 = new TreeNode(4);
  TreeNode * n2 = new TreeNode(2);
  TreeNode * n7 = new TreeNode(7);
  n4->left = n2; n4->right = n7;
  TreeNode * n1 = new TreeNode(1);
  TreeNode * n3 = new TreeNode(3);
  n2->left = n1; n2->right = n3;
  TreeNode * n6 = new TreeNode(6);
  TreeNode * n9 = new TreeNode(9);
  n7->left = n6; n7->right = n9;
  Solution sol;
  sol.invertTree(n4);
  sol.dfs(n4);
  return 0;
}
