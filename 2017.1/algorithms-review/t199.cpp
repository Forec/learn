#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == NULL)
      return res;
    res.push_back(root->val);
    vector<int> leftPart = rightSideView(root->left);
    vector<int> rightPart = rightSideView(root->right);
    res.insert(res.end(), rightPart.begin(), rightPart.end());
    if (leftPart.size() > rightPart.size()){
      res.insert(res.end(), leftPart.begin() + rightPart.size(), leftPart.end());
    }
    return res;
  }
};

int main(){
  Solution sol;
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  TreeNode *n6 = new TreeNode(6);
  n1->left = n2; n1->right = n3;
  n2->right = n5; n5->left = n6;
  n3->right = n4;
  vector<int> ans= sol.rightSideView(n1);
  for (int i =0; i < ans.size(); i++){
    cout << ans[i] << " " ;
  }
  cout << endl;
  return 0;
}
