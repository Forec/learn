#include <iostream>
#include <vector>
#include <string>
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
  void dfs(TreeNode *root, vector<int> & data){
    if (!root)
      return;
    data.push_back(root->val);
    if (root->left)
      dfs(root->left, data);
    if (root->right)
      dfs(root->right, data);
  }
public:
  int getMinimumDifference(TreeNode* root) {
    vector<int> data;
    dfs(root, data);
    if (data.size() < 2)
      return 0;
    sort(data.begin(), data.end());
    int min = data[1] - data[0];
    for (int i = 2; i < data.size(); i++)
      if (data[i] - data[i-1] < min)
        min = data[i] - data[i-1];
    return min;
  }
};

int main(){
  Solution sol;
  TreeNode *root = new TreeNode(1);
  TreeNode *right = new TreeNode(2);
  TreeNode *rleft = new TreeNode(2);
  root->right= right;
  right->left = rleft;
  cout << sol.getMinimumDifference(root) << endl;
  return 0;
}
