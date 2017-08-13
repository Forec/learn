#include <iostream>
#include <map>
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
  // struct DupTreeNode{
  //   int val;
  //   bool calced;
  //   DupTreeNode *left, *right;
  //   DupTreeNode(int x): val(x), left(NULL), right(NULL), calced(false){};
  // };
  // DupTreeNode * generateDupTree(TreeNode *root){
  //   if ()
  // }
  int dfsGenerateTimes(TreeNode *root){
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return root->val;
    int leftSum = 0, rightSum = 0;
    if (root->left != NULL)
      leftSum = dfsGenerateTimes(root->left);
    if (root->right != NULL)
      rightSum = dfsGenerateTimes(root->right);
    root->val = leftSum + rightSum + root->val;
    return root->val;
  }
  void dfsCollectTimes(TreeNode *root, map<int, int> & ans){
    if (root == NULL) return;
    if (ans.count(root->val) > 0){
      ans[root->val]++;
    } else {
      ans[root->val] = 1;
    }
    if (root->left != NULL)
      dfsCollectTimes(root->left, ans);
    if (root->right != NULL)
      dfsCollectTimes(root->right, ans);
  }
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    dfsGenerateTimes(root);
    map<int, int> ans;
    vector<int> res;
    dfsCollectTimes(root, ans);
    int max = 0;
    if (ans.size() == 0)
      return res;
    for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++){
      if (it->second > max){
        max = it->second;
      }
    }
    for (map<int, int>::iterator it = ans.begin(); it != ans.end(); it++){
      //      cout << it->first << " " << it->second << endl;
      if (it->second == max)
        res.push_back(it->first);
    }
    return res;
  }
};

int main(){
  Solution sol;
  TreeNode *root = new TreeNode(5);
  TreeNode *node1 = new TreeNode(2);
  TreeNode *node2 = new TreeNode(-3);
  root->left = node1; root->right = node2;
  vector<int> ans = sol.findFrequentTreeSum(root);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  delete node2;
  delete node1;
  delete root;
  root = new TreeNode(5);
  node1 = new TreeNode(2);
  node2 = new TreeNode(-5);
  root->left = node1; root->right = node2;
  ans = sol.findFrequentTreeSum(root);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  delete node1;
  delete node2;
  delete root;

  ans = sol.findFrequentTreeSum(NULL);
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] << " ";
  cout << endl;

  return 0;
}
