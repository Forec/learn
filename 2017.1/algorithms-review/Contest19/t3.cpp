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
  struct cell{
    TreeNode * node;
    int depth;
    cell(TreeNode * _node, int dep){
      node= _node;
      depth = dep;
    };
  };
public:
  vector<int> findValueMostElement(TreeNode* root) {
    queue<cell> q;
    vector<int> ans;
    if (!root)
      return ans;
    cell rt = cell(root, 0);
    q.push(rt);
    while (!q.empty()){
      cell tmp = q.front();
      q.pop();
      if (tmp.depth >= ans.size()){
        ans.push_back(tmp.node->val);
      }
      if (tmp.node->val > ans[tmp.depth])
        ans[tmp.depth] = tmp.node->val;
      if (tmp.node->left != NULL){
        cell lt = cell(tmp.node->left, tmp.depth+1);
        q.push(lt);
      }
      if (tmp.node->right != NULL){
        cell rrt = cell(tmp.node->right, tmp.depth+1);
        q.push(rrt);
      }
    }
    return ans;
  }
};

int main(){
  Solution sol;
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

  vector<int> ans = sol.findValueMostElement(NULL);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;
  return 0;
}
