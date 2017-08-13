#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
  void dfs(TreeLinkNode* root){
    if (root == NULL)
      return;
    if (root->next)
      cout << root->val << "->" << root->next->val<< endl;
    dfs(root->left);
    dfs(root->right);
  }
  void connect(TreeLinkNode *root) {
    if (root == NULL)
      return;
    if (root->next && root->right){
      root->right->next = root->next->left;
    }
    if (root->left){
      root->left->next = root->right;
      connect(root->left);
    }
    if (root->right)
      connect(root->right);
  }
  // iteration method
  void connect2(TreeLinkNode *root){
    if (!root) return;
    TreeLinkNode *p = root;
    TreeLinkNode *first = NULL;
    while (p){
      if (!first)
        first = p->left;
      if (p->left)
        p->left->next = p->right;
      else
        break;
      if (p->next){
        p->right->next = p->next->left;
        p = p->next;
      } else {
        p = first;
        first = NULL;
      }
    }
  }
};

int main(){
  TreeLinkNode * root = new TreeLinkNode(1);
  TreeLinkNode * node1 = new TreeLinkNode(2);
  TreeLinkNode * node2 = new TreeLinkNode(3);
  TreeLinkNode * node3 = new TreeLinkNode(4);
  TreeLinkNode * node4 = new TreeLinkNode(5);
  TreeLinkNode * node5 = new TreeLinkNode(6);
  TreeLinkNode * node6 = new TreeLinkNode(7);
  root->right = node2; node1->left = node2;
  root->left = node1;
  node1->left = node3; node1->right = node4;
  node2->left = node5; node2->right = node6;
  vector<int> ans;
  Solution sol;
  sol.connect(root);
  sol.dfs(root);
  return 0;
}
