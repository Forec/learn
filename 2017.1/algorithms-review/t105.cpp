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
  TreeNode* buildTreeIterate(vector<int>& preorder, int inl, int inr,
                             vector<int>& inorder, int ptl, int ptr){
    if (inr <= inl || ptr <= ptl)
      return NULL;
    //    cout << inl << " " << inr << " " << ptl << " " << ptr << endl;
    int rootNum = preorder[inl];
    int breakpoint = ptl;
    for (int i = ptl; i < ptr; i++){
      if (inorder[i] == rootNum){
        breakpoint = i;
        break;
      }
    }
    TreeNode * root = new TreeNode(rootNum);
    TreeNode * left = buildTreeIterate(preorder, inl + 1, breakpoint - ptl + inl + 1,
                                       inorder, ptl, breakpoint);
    TreeNode * right = buildTreeIterate(preorder, inl + breakpoint - ptl + 1, inr,
                                        inorder, breakpoint + 1, ptr);
    root->left = left;
    root->right = right;
    return root;
  }
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeIterate(preorder, 0, preorder.size(),
                            inorder, 0, inorder.size());
  }
};

void dfs(TreeNode * root){
  if(root == NULL)
    return;
  dfs(root->left);
  dfs(root->right);
  cout << root->val << " ";
}

int main(){
  vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
  vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};//{4, 5, 2, 6, 7, 3, 1};
  Solution sol;
  TreeNode *root = sol.buildTree(preorder, inorder);
  dfs(root);
  cout << endl;
  return 0;
}
