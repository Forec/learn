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
  void connect_failed(TreeLinkNode *root) {
    if (root == NULL)
      return;
    if (root->left){
      if (root->right)
        root->left = root->right;
      else {
        TreeLinkNode *tmp = root;
        while (root->next && root->next->left == NULL && root->next->right == NULL)
          root = root->next;
        if (root->next == NULL)
          tmp->left->next = NULL;
        else{
          if (root->next->left)
            tmp->left->next = root->next->left;
          else
            tmp->left->next = root->next->right;
        }
        root = tmp;
      }
    }
    if (root->right){
      TreeLinkNode * tmp = root;
      while (root->next && root->next->left == NULL && root->next->right == NULL)
        root = root->next;
      if (root->next == NULL)
        tmp->right->next = NULL;
      else{
        if (root->next->left)
          tmp->right->next = root->next->left;
        else
          tmp->right->next = root->next->right;
      }
      root = tmp;
    }
    if (root->left)
      connect(root->left);
    if (root->right)
      connect(root->right);
  }
  // Best Solution, from https://discuss.leetcode.com/topic/8447/simple-solution-using-constant-space/2
  void connect(TreeLinkNode * root){
    while (root != NULL){
      TreeLinkNode * tempChild = new TreeLinkNode(0);
      TreeLinkNode * curChild = tempChild;
      while (root != NULL){
        if (root->left){
          curChild->next = root->left;
          curChild = curChild->next;
        }
        if (root->right){
          curChild->next = root->right;
          curChild = curChild->next;
        }
        root = root->next;
      }
      root = tempChild->next;
    }
  }

  // another good solution, from https://discuss.leetcode.com/topic/1106/o-1-space-o-n-complexity-iterative-solution/7
  // the kernel is similar.
  void connect2(TreeLinkNode *root){
    TreeLinkNode * head = root, *prev = NULL, *curr = NULL;
    while (head){
      curr = head;
      prev = head = NULL;
      while (curr){
        if(curr->left){
          if (prev)
            prev->next = curr->left;
          else
            head = curr->left;
          prev = curr->left;
        }
        if (curr->right){
          if (prev)
            prev->next = curr->right;
          else
            head = curr->right;
          prev = curr->right;
        }
        curr = curr->next;
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
