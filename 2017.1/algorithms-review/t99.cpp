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
  void recoverTree(TreeNode* root) {
    TreeNode * pre = NULL;
    TreeNode * cur = root;
    TreeNode * p1 = NULL, * p2 = NULL;
    bool find = false;
    while (cur){
      if (!cur->left){
        if (pre && pre->val > cur->val){
          if (!find){
            p1 = pre;
            find = true;
          }
          p2 = cur;
        }
        pre = cur;
        cur = cur->right;
      } else {
        TreeNode * tmp = cur->left;
        while (tmp->right && tmp->right != cur)
          tmp = tmp->right;
        if (!tmp->right){
          tmp->right = cur;
          cur = cur->left;
        } else {
          if (pre && pre->val > cur->val){
            if (!find){
              p1 = pre;
              find = true;
            }
            p2 = cur;
          }
          tmp->right = NULL;
          pre = cur;
          cur = cur->right;
        }
      }
    }
    if (p1 && p2){
      int temp = p1->val;
      p1->val = p2->val;
      p2->val = temp;
    }
  }
  void dfs(TreeNode * root){
    if (!root) return;
    dfs(root->left);
    cout << root->val << " ";
    dfs(root->right);
  }
};

int main(){
  TreeNode * root = new TreeNode(4);
  TreeNode * node1 = new TreeNode(6); // 2
  TreeNode * node2 = new TreeNode(5);
  TreeNode * node3 = new TreeNode(1);
  TreeNode * node4 = new TreeNode(3);
  TreeNode * node5 = new TreeNode(2); // 6
  root->left = node1; root->right = node2;
  node1->left = node3; node1->right = node4;
  node2->right = node5;
  Solution sol;
  sol.recoverTree(root);
  sol.dfs(root);
  cout << endl;
  return 0;
}
