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
  TreeNode* buildTreeIterate(vector<int>& inorder, int inl, int inr,
                             vector<int>& postorder, int ptl, int ptr){
    if (inr <= inl || ptr <= ptl)
      return NULL;
    //    cout << inl << " " << inr << " " << ptl << " " << ptr << endl;
    int rootNum = postorder[ptr-1];
    int breakpoint = inl;
    for (int i = inl; i < inr; i++){
      if (inorder[i] == rootNum){
        breakpoint = i;
        break;
      }
    }
    TreeNode * root = new TreeNode(rootNum);
    TreeNode * left = buildTreeIterate(inorder, inl, breakpoint,
                                       postorder, ptl, ptl + breakpoint - inl);
    TreeNode * right = buildTreeIterate(inorder, breakpoint + 1, inr,
                                        postorder, ptl + breakpoint - inl, ptr - 1);
    root->left = left;
    root->right = right;
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    // int rootNum = postorder[postorder.size() - 1];
    // int breakpoint;
    // for (int i = 0; i < inorder.size(); i++){
    // }
    return buildTreeIterate(inorder, 0, inorder.size(),
                            postorder, 0, postorder.size());
  }
};

void dfs(TreeNode * root){
  if(root == NULL)
    return;
  cout << root->val << " ";
  dfs(root->left);
  dfs(root->right);
}

int main(){
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
  vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
  Solution sol;
  TreeNode *root = sol.buildTree(inorder, postorder);
  dfs(root);
  cout << endl;
  return 0;
}
