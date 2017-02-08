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
  vector<int> preorderTraversal(TreeNode* root) {
    if (root == NULL)
      return vector<int>();
    vector<int> ans;
    stack<TreeNode*> s;
    s.push(root);
    while (!s.empty()){
      TreeNode* cur = s.top();
      ans.push_back(cur->val);
      s.pop();
      if (cur->right != NULL) // stack is FILO
        s.push(cur->right);
      if (cur->left != NULL)
        s.push(cur->left);
    }
    return ans;
  }

  // The following solution is wonderful!
  vector<int> preorderTraversalLoop(TreeNode* root) {
    vector<int> v;
    if(!root) return v;
    TreeNode* temp = root, *prev;
    while(temp){
      if(!temp->left){
        v.push_back(temp->val);
        temp = temp->right;
      }else{
        prev = temp->left;
        while(prev->right&&(prev->right != temp))
          prev = prev->right;
        if(!prev->right){
          v.push_back(temp->val);
          prev->right = temp;
          temp = temp->left;
        }else{
          prev->right = NULL;
          temp = temp->right;
        }
      }
    }
  }
};

int main(){
  TreeNode * root = new TreeNode(1);
  TreeNode * node1 = new TreeNode(2);
  TreeNode * node2 = new TreeNode(3);
  root->left = node1; node1->right = node2;
  vector<int> ans;
  Solution sol;
  ans = sol.preorderTraversal(root);
  for (int i = 0;i < ans.size(); i++){
      cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
