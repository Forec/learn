#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode* cur = root;
    while (!s.empty() || cur){
      if (cur){
        s.push(cur);
        cur = cur->left;
      } else {
        TreeNode *tmp = s.top();
        ans.push_back(tmp->val);
        s.pop();
        cur = tmp->right;
      }
    }
    return ans;
  }
};

// other solutions:
// Solution2 will change the node, we can use an unordered_map to avoid this,
// use map[TreeNode *node] to record whether node is alreay visited.
class Solution2 {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vector;
    if(!root)
      return vector;
    stack<TreeNode *> stack;
    stack.push(root);
    while(!stack.empty())
      {
        TreeNode *pNode = stack.top();
        if(pNode->left)
          {
            stack.push(pNode->left);
            pNode->left = NULL;   // here, use map to avoid changing nodes.
          }
        else
          {
            vector.push_back(pNode->val);
            stack.pop();
            if(pNode->right)
              stack.push(pNode->right);
          }
      }
    return vector;
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  root->right = node1; node1->left = node2;
  vector<int> ans;
  Solution sol;
  ans = sol.inorderTraversal(root);
  for (int i = 0;i < ans.size(); i++){
      cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
