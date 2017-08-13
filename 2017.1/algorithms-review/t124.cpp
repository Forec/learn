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
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  int dfs(TreeNode* root, int & maxm){
    if (!root) return 0;
    if (!root->left && !root->right){
      if (root->val > maxm)
        maxm = root->val;
      return root->val;
    }
    int left = 0, right = 0;
    if (root->left)
      left = max(dfs(root->left, maxm), 0);
    if (root->right)
      right = max(dfs(root->right, maxm), 0);
    int ans = left + right + root->val;
    if (ans > maxm)
      maxm = ans;
    return max(left, right) + root->val;
  }
public:
  int maxPathSum(TreeNode* root) {
    if (!root)
      return 0;
    int maxm = root->val;
    dfs(root, maxm);
    return maxm;
  }
};

int main(){
  TreeNode * root = new TreeNode(5);
  TreeNode * node1 = new TreeNode(4);
  TreeNode * node2 = new TreeNode(8);
  TreeNode * node3 = new TreeNode(11);
  TreeNode * node4 = new TreeNode(13);
  TreeNode * node5 = new TreeNode(4);
  TreeNode * node6 = new TreeNode(7);
  TreeNode * node7 = new TreeNode(2);
  TreeNode * node8 = new TreeNode(1);
  root->left = node1; root->right = node2;
  node1->left = node3; node3->left = node6;
  node3->right = node7; node2->right = node5;
  node2->left = node4; node5->right = node8;
  Solution sol;
  cout<< sol.maxPathSum(root) << endl;
  return 0;
}
