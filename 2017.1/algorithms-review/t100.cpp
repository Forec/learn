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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};

int main(){
  Solution sol;
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  root->left = node1; root->right=  node2;
  cout << sol.isSameTree(root, root) << " " << sol.isSameTree(root, node1) << endl;
  return 0;
}
