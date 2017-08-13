#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
private:
  struct TreeNode {
    long long val;
    int times;
    int leftChildNums;
    int rightChildNums;
    TreeNode *parent;
    TreeNode * left;
    TreeNode * right;
    TreeNode (long long _v, TreeNode *par): val(_v), leftChildNums(0),
                                      rightChildNums(0), left(NULL),
                                      right(NULL), times(1),
                                      parent(par){};
  };
  void updateChildNum(TreeNode * node, int add){
    if (node!= NULL && node->parent != NULL){
      if (node == node->parent->left){
        node->parent->leftChildNums += add;
        updateChildNum(node->parent, add);
      } else if (node == node->parent->right){
        node->parent->rightChildNums += add;
        updateChildNum(node->parent, add);
      }
    }
  }
  void insertNode(TreeNode *root,long long val){
    if (root==NULL)return;
    if (val == root->val) {
      root->times++;
      updateChildNum(root, 1);
      return;
    }
    if (root->left == NULL && val < root->val){
      TreeNode *node = new TreeNode(val, root);
      root->left = node;
      updateChildNum(node, 1);
      return;
    } else if (root->right == NULL && val > root->val){
      TreeNode *node = new TreeNode(val, root);
      root->right = node;
      updateChildNum(node, 1);
      return;
    }
    if (root->left != NULL && val < root->val)
      insertNode(root->left, val);
    else if (root->right != NULL && val > root->val)
      insertNode(root->right, val);
  }
  int searchTree(TreeNode *root, long long val){
    if (root == NULL) return 0;
    if (val == root->val){
      return root->rightChildNums;
    }
    if (val < root->val){
      return searchTree(root->left, val) + root->times + root->rightChildNums;
    }
    if (val > root->val){
      return searchTree(root->right, val);
    }
  }
public:
  int reversePairs(vector<int>& nums) {
    if (nums.size()== 0 || nums.size() == 1)
      return 0;
    TreeNode * root = new TreeNode(nums[0], NULL);
    int ans = 0;
    for (int i = 1; i < nums.size(); i++){
      long long toFind = (long long)(nums[i]) * 2;
      ans += searchTree(root, toFind);
      insertNode(root, nums[i]);
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para7 = {2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
  vector<int> para3 = {1, 3, 4, 3, 0}; // 4
  vector<int> para = {1, 3, 2, 3, 1};
  vector<int> para2 = {2, 4, 3, 5, 1};
  vector<int> para4 = {};
  vector<int> para5 = {1};
  vector<int> para6 = {3, 1}; // 1
  cout << (sol.reversePairs(para7) == 0) << endl;
  cout << (sol.reversePairs(para) == 2) << endl;
  cout << (sol.reversePairs(para2) == 3) << endl;
  cout << (sol.reversePairs(para4) == 0) << endl;
  cout << (sol.reversePairs(para5) == 0) << endl;
  cout << (sol.reversePairs(para6) == 1) << endl;
  cout << (sol.reversePairs(para3) == 4) << endl;
  return 0;
}
