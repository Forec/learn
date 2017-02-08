#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
 int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  struct cell{
    TreeNode * node;
    int depth;
    cell(TreeNode* _node, int _dep){
      node = _node;
      depth = _dep;
    };
  };
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;
    queue<cell> q;
    q.push(cell(root, 1));
    while (!q.empty()){
      cell cur = q.front();
      q.pop();
      if (ans.size() < cur.depth)
        ans.push_back(vector<int>(1, cur.node->val));
      else
        ans[cur.depth-1].push_back(cur.node->val);
      if (cur.node->left != NULL)
        q.push(cell(cur.node->left, cur.depth + 1));
      if (cur.node->right != NULL)
        q.push(cell(cur.node->right, cur.depth + 1));
    }
    return ans;
  }
};

int main(){
  Solution sol;
  TreeNode *root = new TreeNode(3);
  TreeNode *node1 = new TreeNode(9);
  TreeNode *node2 = new TreeNode(20);
  TreeNode *node3 = new TreeNode(15);
  TreeNode *node4 = new TreeNode(7);
  root->left = node1; root->right = node2;
  node2->left = node3; node2->right = node4;
  vector<vector<int>> ans = sol.levelOrder(root);
  for (int i = 0; i < ans.size(); i++){
    for (int j = 0; j< ans[i].size(); j++){
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
