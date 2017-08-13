#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  int collect(TreeNode *root, int sum){
    if (!root) return 0;
    return (sum == root->val) + collect(root->left, sum - root->val) + collect(root->right, sum - root->val);
  }
public:
  int pathSum(TreeNode* root, int sum){
    if (!root) return 0;
    return collect(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
  }
};

int main(){
  TreeNode * root = new TreeNode(10);
  TreeNode * node1 = new TreeNode(5);
  TreeNode * node2 = new TreeNode(-3);
  TreeNode * node3 = new TreeNode(3);
  TreeNode * node4 = new TreeNode(2);
  TreeNode * node5 = new TreeNode(11);
  TreeNode * node6= new TreeNode(3);
  TreeNode * node7= new TreeNode(-2);
  TreeNode * node8= new TreeNode(1);
  root->left = node1; root->right = node2;
  node1->left = node3; node4->right = node8;
  node2->right = node5; node3->right = node7;
  node3->left = node7; node1->right = node4;
  int ans;
  Solution sol;
  ans = sol.pathSum(root, 8);
  cout << ans << endl;
  return 0;
}
