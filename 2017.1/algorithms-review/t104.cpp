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
  int maxDepth(TreeNode* root) {
    if (root == NULL)
      return 0;
    int left = 0, right = 0;
    if (root->left != NULL)
      left = maxDepth(root->left);
    if (root->right != NULL)
      right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
  }
};

int main(){
  Solution sol;
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  TreeNode * node3 = new TreeNode(4);
  root->left = node1;
  root->right = node2;
  node2->right = node3; // depth should be 3;
  cout << sol.maxDepth(root) << endl;
  return 0;
}
