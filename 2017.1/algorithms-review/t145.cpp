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

// postorder is exactly the reverse of preorder
// There exists a solution with O(n) time and O(1) space!
// see https://discuss.leetcode.com/topic/14473/0-ms-clear-c-solutions-iterative-recursive-morris-traversal-3-different-solutions/2


class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode* cur = root, *pre = NULL;
    while (!s.empty() || cur){
      if (cur){
        s.push(cur);
        cur = cur->left;
      } else {
        TreeNode *tmp = s.top();
        if (tmp->right && pre != tmp->right)
          cur = tmp->right;
        else{
          ans.push_back(tmp->val);
          pre = tmp;
          s.pop();
        }
      }
    }
    return ans;
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  root->right = node1; node1->left = node2;
  vector<int> ans;
  Solution sol;
  ans = sol.postorderTraversal(root);
  for (int i = 0;i < ans.size(); i++){
      cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
