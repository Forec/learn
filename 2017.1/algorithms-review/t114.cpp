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
public:
  void dfs(TreeNode *root){
    if (!root) return;
    cout << root->val << endl;
    dfs(root->left); dfs(root->right);
  }
  TreeNode * generate(TreeNode* root){
    if (!root) return NULL;
    if (root->right == NULL && root->left == NULL) return root;
    if (root->left){
      TreeNode * leftLast = generate(root->left);
      TreeNode * rightLast = generate(root->right);
      TreeNode * temp = root->right;
      root->right = root->left;
      root->left = NULL;
      leftLast->right = temp;
      return rightLast;
    } else {
      return generate(root->right);
    }
  }
  void flatten1(TreeNode *root){
    generate(root);
  }
  void flatten(TreeNode* root) {
    if (root == NULL)
      return;
    stack<TreeNode *> s;
    s.push(root);
    TreeNode* last = NULL;
    while (!s.empty()){
      TreeNode* p = s.top();
      s.pop();
      if (last)
        last->right = p;
      last = p;
      if (p->right){
        s.push(p->right);
        p->right = NULL;
      }
      if (p->left){
        s.push(p->left);
        p->left = NULL;
      }
    }
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  TreeNode * node3 = new TreeNode(4);
  TreeNode * node4 = new TreeNode(5);
  TreeNode * node5 = new TreeNode(6);
  root->left = node1; root->right = node4;
  node1->left = node2; node1->right = node3;
  node4->right = node5;
  Solution sol;
  sol.flatten1(root);
  sol.dfs(root);
  return 0;
}
