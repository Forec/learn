#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  void dfs(TreeNode *root, int depth, int &max, int &maxdepth){
    if (root == NULL){
      return;
    }
    if (!root->left && !root->right){
      if (depth > maxdepth){
        max = root->val;
        maxdepth = depth;
      }
      return;
    }
    if (root->left)
      dfs(root->left, depth+1, max, maxdepth);
    if (root->right){
      dfs(root->right, depth+1, max,maxdepth);
    }
  }
public:
  int findLeftMostNode(TreeNode* root) {
    if (root==NULL)return 0;
    int maxdepth = 0;
    int max = root->val;
    dfs(root, 0, max, maxdepth);
    return max;
  }
};

int main(){
  TreeNode *root = new TreeNode(1);
  TreeNode *node2 = new TreeNode(2);
  TreeNode *node3 = new TreeNode(3);
  TreeNode * node4=  new TreeNode(4);
  TreeNode * node5=  new TreeNode(5);
  TreeNode * node6=  new TreeNode(6);
  TreeNode * node7=  new TreeNode(7);
  root->left = node2; root->right = node3;
  node2->left = node4;
  node3->left = node5;
  node3->right = node6;
  node5->left = node7;

  TreeNode *root2 = new TreeNode(2);
  TreeNode *node11 = new TreeNode(1);
  TreeNode *node21 = new TreeNode(3);
  root2->left = node11; root2->right = node21;
  Solution sol;
  cout << sol.findLeftMostNode(root2) << endl;
  return 0;
}
