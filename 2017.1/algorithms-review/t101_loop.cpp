#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if (root == NULL)
      return true;
    if (root->left == NULL && root->right == NULL)
      return true;
    queue<TreeNode*> Q1, Q2;
    Q1.push(root->left); Q2.push(root->right);
    while (!Q1.empty() && !Q2.empty()){
      TreeNode * tmp1 = Q1.front();
      TreeNode * tmp2 = Q2.front();
      Q1.pop(); Q2.pop();
      if ((!tmp1 && tmp2) || (tmp1 && !tmp2))
        return false;
      if (tmp1 && tmp2){
        if (tmp1->val != tmp2->val)
          return false;
        Q1.push(tmp1->left);
        Q2.push(tmp2->right);
        Q1.push(tmp1->right);
        Q2.push(tmp2->left);
      }
    }
    return true;
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(2);
  TreeNode * node3 = new TreeNode(3);
  TreeNode * node4 = new TreeNode(4);
  TreeNode * node5 = new TreeNode(4);
  TreeNode * node6 = new TreeNode(3);
  root->left = node1; root->right = node2;
  node1->left = node3; node1->right = node4;
  node2->left = node5; node2->right = node6;
  Solution sol;
  cout << sol.isSymmetric(root) << endl;
  return 0;
}

