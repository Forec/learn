#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  struct FNode {
    int deep;
    int val;
    FNode *left, *right;
    FNode(int _d,int v) : deep(_d), val(v), left(NULL), right(NULL) {};
  };
  FNode * generateTH(TreeNode * root){
    if (root == NULL)
      return NULL;
    FNode * nd = new FNode(1, root->val);
    if (root->left != NULL){
      nd->left = generateTH(root->left);
      nd->deep += nd->left->deep;
    }
    if (root->right != NULL){
      nd->right = generateTH(root->right);
      nd->deep += nd->right->deep;
    }
    return nd;
  }
  int search1(FNode * root, int k){
    if (k <= 0 || k > root->deep)
      return -1;
    if (root->left){
      if (root->left->deep >= k)
        return search(root->left, k);
      if (root->left->deep == k-1)
        return root->val;
      return search(root->right, k - 1 - root->left->deep);
    } else {
      if (k == 1)
        return root->val;
      return search(root->right, k - 1);
    }
  }
  int search(FNode * root, int k){
    if (root == NULL)
      return -1;
    int rootNum = root->deep - (root->right == NULL ? 0 : root->right->deep);
    if (k == rootNum)
      return root->val;
    if (k < rootNum){
      return search(root->left, k);
    } else {
      return search(root->right, k - rootNum);
    }
  }
  void dfs(FNode *root){
    if (!root)
      return;
    cout << root->val << " " << root->deep << endl;
    dfs(root->left);
    dfs(root->right);
  }
public:
  int kthSmallest(TreeNode* root, int k) {
    FNode * nt = generateTH(root);
    return search(nt, k);
  }
};

int main(){
  TreeNode * n1 = new TreeNode(1);
  TreeNode * n2 = new TreeNode(2);
  TreeNode * n3 = new TreeNode(3);
  TreeNode * n4 = new TreeNode(4);
  TreeNode * n5 = new TreeNode(5);
  TreeNode * n6 = new TreeNode(6);
  TreeNode * n7 = new TreeNode(7);
  n5->left = n3;
  n3->left = n2;
  n2->left = n1;
  n3->right = n4;
  n5->right = n7;
  n7->left = n6;
  Solution sol;
  cout << sol.kthSmallest(n5, 7) << endl;
  return 0;
}
