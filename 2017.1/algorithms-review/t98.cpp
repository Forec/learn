#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  bool validate(TreeNode *root, TreeNode * &prev){
    if (!root) return true;
    if (!validate(root->left, prev)) return false;
    if (prev && prev->val >= root->val) return false;
    prev = root;
    return validate(root->right, prev);
  }
public:
  bool isValidBST(TreeNode* root) {
    TreeNode * prev = NULL;
    return validate(root, prev);
  }
};

int main(){
  TreeNode * root = new TreeNode(4);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(5);
  TreeNode * node3 = new TreeNode(1);
  TreeNode * node4 = new TreeNode(3);
  TreeNode * node5 = new TreeNode(6);
  root->left = node1; root->right = node2;
  node1->left = node3; node1->right = node4;
  node2->right = node5;
  Solution sol;
  cout << sol.isValidBST(root) << endl;
  return 0;
}
