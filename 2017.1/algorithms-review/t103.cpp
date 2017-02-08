#include <iostream>
#include <queue>
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
  inline int max(int x, int y) { return x > y ? x : y; }
  int getHeight(TreeNode *root) {
    if (root == NULL)
      return 0;
    return max(getHeight(root->left), getHeight(root->right)) + 1;
  }
  void generate(vector<vector<int>> &ans, TreeNode *root, int level) {
    if (root == NULL)
      return;
    //    cout << (level & 1) << " " << (level % 2) << " " << level << endl;
    if ((level & 1) == 0)
      ans[level].push_back(root->val);
    else
      ans[level].insert(ans[level].begin(), root->val);
    generate(ans, root->left, level + 1);
    generate(ans, root->right, level + 1);
  }

public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    int height = getHeight(root);
    if (root == NULL || height == 0)
      return ans;
    ans.resize(height);
    generate(ans, root, 0);
    return ans;
  }
};

int main() {
  Solution sol;
  TreeNode *root = new TreeNode(3);
  TreeNode *node1 = new TreeNode(9);
  TreeNode *node2 = new TreeNode(20);
  TreeNode *node3 = new TreeNode(15);
  TreeNode *node4 = new TreeNode(7);
  root->left = node1;
  root->right = node2;
  node2->left = node3;
  node2->right = node4;
  vector<vector<int>> ans = sol.zigzagLevelOrder(root);
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
