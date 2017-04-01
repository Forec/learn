#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
private:
  unordered_set<TreeNode*> vis;
  unordered_map<TreeNode*, TreeNode*> par;
  TreeNode *pn, *qn;
  TreeNode *res;
  TreeNode * find(TreeNode *u){
    return par[u] == u ? u : find(par[u]);
  }
  void init(TreeNode * root){
    if (root == NULL)
      return;
    par[root] = root;
    init(root->left);
    init(root->right);
  }
  void tarjan(TreeNode * root){
    if (root == NULL)
      return;
    vis.insert(root);
    if (root == pn || root == qn){
      if (root == pn && vis.count(qn) >= 1)
        res = find(qn);
      if (root == qn && vis.count(pn) >= 1)
        res = find(pn);
    }
    if (root->left != NULL && vis.count(root->left) == 0){
      tarjan(root->left);
      par[root->left] = root;
    }
    if (root->right != NULL && vis.count(root->right) == 0){
      tarjan(root->right);
      par[root->right] = root;
    }
  }
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    res = NULL;
    pn = p; qn = q;
    vis.clear();
    par.clear();
    init(root);
    tarjan(root);
    return res;
  }
};

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
  }
};

int main(){
  TreeNode * n6 = new TreeNode(6);
  TreeNode * n2 = new TreeNode(2);
  TreeNode * n8 = new TreeNode(8);
  TreeNode * n0 = new TreeNode(0);
  TreeNode * n4 = new TreeNode(4);
  TreeNode * n7 = new TreeNode(7);
  TreeNode * n9 = new TreeNode(9);
  TreeNode * n3 = new TreeNode(3);
  TreeNode * n5 = new TreeNode(5);
  n6->left = n2; n6->right = n8;
  n2->left = n0; n2->right = n4;
  n4->left = n3; n4->right = n5;
  n8->left = n7; n8->right = n9;
  Solution sol;
  TreeNode * ans1 = sol.lowestCommonAncestor(n6, n2, n8);
  cout << (ans1 != NULL && 6 == ans1->val) << endl;
  TreeNode * ans2 = sol.lowestCommonAncestor(n6, n2, n4);
  cout << (ans2 != NULL && 2 == ans2->val) << endl;
  TreeNode * ans3 = sol.lowestCommonAncestor(n6, n0, n5);
  cout << (ans3 != NULL && 2 == ans3->val) << endl;
  return 0;
}
