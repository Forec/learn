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
  inline int abs(int x){
    return x < 0 ? -x : x;
  }
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  int getHeight(TreeNode * root){
    if (root == NULL)
      return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    if (leftHeight == -1 || rightHeight == -1)
      return -1;
    if (abs(rightHeight - leftHeight) <= 1)
      return max(leftHeight, rightHeight) + 1;
    else
      return -1;
  }
public:
  bool isBalanced(TreeNode* root) {
    if (root == NULL)
      return true;
    return !(getHeight(root) == -1);
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2=  new TreeNode(3);
  TreeNode * node3 = new TreeNode(4);
  root->left = node1; root->right = node2;
  node1->left = node3;
  Solution sol;
  cout << sol.isBalanced(root) << endl;
  TreeNode * node4 = new TreeNode(5);
  node3->left = node4;
  cout << sol.isBalanced(root) << endl;
  return 0;
}
