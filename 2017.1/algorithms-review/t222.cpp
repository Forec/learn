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
public:
  int countNodes(TreeNode* root) {
    if(!root) return 0;
    int hl=0, hr=0;
    TreeNode *l=root, *r=root;
    while(l) {hl++;l=l->left;}
    while(r) {hr++;r=r->right;}
    if(hl==hr) return pow(2,hl)-1;
    return 1+countNodes(root->left)+countNodes(root->right);
  }
};

int main(){
  TreeNode *r = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  r->left = n1;
  r->right = n2;
  Solution sol;
  cout << sol.countNodes(r) << endl;
  return 0;
}
