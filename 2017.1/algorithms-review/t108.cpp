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
  TreeNode * build(int left, int right, vector<int> & nums){
    if (left >= right)
      return NULL;
    int mid = left + ((right - left) >> 1);
    TreeNode * node = new TreeNode(nums[mid]);
    node->left = build(left, mid, nums);
    node->right = build(mid+1, right, nums);
    return node;
  }
public:
  TreeNode* sortedArrayToBST(vector<int> & nums) {
    return build(0, nums.size(), nums);
  }
  void dfs(TreeNode *root){
    if (!root) return;
    cout << root->val << endl;
    dfs(root->left);
    dfs(root->right);
  }
};

int main(){
  Solution sol;
  vector<int> para = {1, 2, 3, 4, 5};
  TreeNode * ans = sol.sortedArrayToBST(para);
  sol.dfs(ans);
  return 0;
}
