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
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL)
      return false;
    if (root->val == sum && root->left == NULL && root->right == NULL)
      return true;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

int main(){
  TreeNode * root = new TreeNode(5);
  TreeNode * node1 = new TreeNode(4);
  TreeNode * node2 = new TreeNode(3);
  TreeNode * node3 = new TreeNode(11);
  TreeNode * node4 = new TreeNode(13);
  TreeNode * node5 = new TreeNode(2);
  root->left = node1; root->right = node2;
  node1->left = node3; node3->right = node5;
  node2->left = node4;
  Solution sol;
  cout << sol.hasPathSum(root, 22) <<
    " " << sol.hasPathSum(root, 21)<<
    " " << sol.hasPathSum(root, 23)<< endl;    ; // 1 1 0
  return 0;
}
