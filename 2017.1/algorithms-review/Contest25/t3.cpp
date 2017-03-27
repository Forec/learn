#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  vector<int> leftMost(TreeNode *root){
    vector<int> res;
    if (root == NULL)
      return res;
    root = root->left;
    while (root != NULL){
      res.push_back(root->val);
      if (root->left)
        root = root->left;
      else
        root = root->right;
    }
    return res;
  }
  vector<int> rightMost(TreeNode *root){
    vector<int> res;
    if (root == NULL)
      return res;
    root = root->right;
    while (root != NULL){
      res.push_back(root->val);
      if (root->right)
        root = root->right;
      else
        root = root->left;
    }
    return res;
  }
  void getLeafs(TreeNode *root, vector<int> &res){
    if (root == NULL)
      return;
    if (root->left == NULL && root->right == NULL)
      res.push_back(root->val);
    if (root->left)
      getLeafs(root->left, res);
    if (root->right)
      getLeafs(root->right, res);
  }
public:
  vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> leafs;
    getLeafs(root, leafs);
    vector<int> leftM = leftMost(root);
    vector<int> rightM = rightMost(root);
    vector<int> res;
    if (root == NULL)
      return res;
    res.push_back(root->val);
    res.insert(res.end(), leftM.begin(), leftM.end());
    res.insert(res.end(), leafs.begin() + (leftM.size() >= 1 || (!root->left && !root->right)), leafs.end());
    if (rightM.size() > 1){
      reverse(rightM.begin(), rightM.end());
      res.insert(res.end(), rightM.begin() + 1, rightM.end());
    }
    return res;
  }
};

int main(){
  Solution sol;
  TreeNode *n1 = new TreeNode (1);
  TreeNode *n2 = new TreeNode (2);
  TreeNode *n3 = new TreeNode (3);
  TreeNode *n4 = new TreeNode (4);
  n1->right = n2;
  n2->left = n3;
  n2->right = n4;
  vector<int> res1 = sol.boundaryOfBinaryTree(n1);
  for (int i = 0; i < res1.size(); i++)
    cout << res1[i] << " ";
  cout << endl;
  TreeNode *n5 = new TreeNode(5);
  TreeNode *n6 = new TreeNode(6);
  TreeNode *n7 = new TreeNode(7);
  TreeNode *n8 = new TreeNode(8);
  TreeNode *n9 = new TreeNode(9);
  TreeNode *n10 = new TreeNode(10);
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;
  n5->left = n7;
  n5->right = n8;
  n3->left = n6;
  n6->left = n9;
  n6->right = n10;
  vector<int> res2 = sol.boundaryOfBinaryTree(n1);
  for (int i = 0; i < res2.size(); i++){
    cout << res2[i] << " ";
  }
  cout<<endl;
  n1->left = n2; n1->right = n6;
  n2->right = n3; n2->left = NULL;
  n3->left = n4; n3->right = n5;
  n4->left = n4->right = n5->left = n5->right = NULL;
  n6->right = n7->left=  n7->right= NULL;
  n6->left = n7;
  vector<int> res3 = sol.boundaryOfBinaryTree(n1);
  for (int i = 0; i < res3.size(); i++){
    cout << res3[i] << " ";
  }
  cout << endl;
  n1->left = n2; n1->right = NULL;
  n2->left = NULL; n2->right = n3;
  n1->right = n4;
  n4->left = n4->right = NULL;
  n3->left = n3->right = NULL;
  vector<int> res4 = sol.boundaryOfBinaryTree(n1);
  for (int i = 0; i < res4.size(); i++){
    cout << res4[i] << " ";
  }
  cout << endl;
  n1->left = n1->right = NULL;
  vector<int> res5 = sol.boundaryOfBinaryTree(n1);
  for (int i = 0; i <res5.size(); i++){
    cout << res5[i] << " ";
  }
  cout << endl;
  return 0;
}
