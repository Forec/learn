#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

typedef pair<int, int> pii;
class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
  int ans;
  pii dfs(TreeNode * c){
    if (c ==NULL)
      return pii(0, 0);
    pii la = dfs(c->left), ra = dfs(c->right);
    int d = 1, u = 1;
    if (c->left && c->left->val + 1 == c->val)
      d = max(d, 1 + la.first);
    if (c->right && c->right->val + 1 == c->val)
      d = max(d, 1 + ra.first);
    if (c->left && c->left->val -1 == c->val)
      u = max(u, 1 + la.second);
    if (c->right && c->right->val -1 == c->val)
      u = max(u, 1 + ra.second);
    ans = max(ans, d + u - 1);
    return pii(d, u);
  }
public:
  int longestConsecutive(TreeNode* root) {
    ans = 0;
    dfs(root);
    return ans;
  }
};

class Solution1 {
private:
  inline int abs(int x){
    long long p = x;
    return p < 0 ? -p : p;
  }
  void generatel(vector<int> &ll, vector<int> & resl, int var){
    if (ll.size() != 0){
      if (ll.size() == 1 && abs(ll[0] - var) == 1)
        resl.push_back(ll[0]);
      else {
        int lastI = ll.size()-1;
        if (var - ll[lastI] == ll[lastI] - ll[lastI-1] && abs(var-ll[lastI]) == 1)
          resl.insert(resl.end(), ll.begin(), ll.end());
      }
    }
    resl.push_back(var);
  }
  void generater(vector<int> &ll, vector<int> & resl, int var){
    reverse(ll.begin(), ll.end());
    resl.push_back(var);
    if (ll.size() != 0){
      if (ll.size() == 1 && abs(ll[0] - var) == 1)
        resl.push_back(ll[0]);
      else {
        if (var - ll[0] == ll[0] - ll[1] && abs(ll[0] - ll[1]) == 1)
          resl.insert(resl.end(), ll.begin(), ll.end());
      }
    }
  }
  pair<vector<int>, vector<int>> dfs(TreeNode *root, int &ans){
    if (root == NULL)
      return make_pair<vector<int>, vector<int>>(vector<int>(), vector<int>());
    if (root->left == NULL && root->right == NULL){
      vector<int> res = {root->val};
      return make_pair(res, res);
    }
    int var = root->val;
    pair<vector<int>, vector<int>> left = dfs(root->left, ans);
    pair<vector<int>, vector<int>> right = dfs(root->right, ans);
    vector<int> ll = left.first;
    vector<int> lr = left.second;
    vector<int> rl = right.first;
    vector<int> rr = right.second;
    vector<int> resll, reslr, resrl, resrr;
    generatel(ll, resll, var);
    generatel(lr, reslr, var);
    generater(rl, resrl, var);
    generater(rr, resrr, var);
    vector<int> resl = resll.size() > reslr.size() ? resll : reslr;
    vector<int> resr = resrl.size() > resrr.size() ? resrl : resrr;
    cout << "resl for treenode " << var << ": " ;
    for (int i = 0; i< resl.size(); i++)
      cout << resl[i] << " ";
    cout << endl << "resr for treenode " << var << ": ";
    for (int i = 0; i < resr.size(); i++)
      cout << resr[i] << " ";
    cout << endl;
    ans = ans >= resl.size() ? ans : resl.size();
    ans = ans >= resr.size() ? ans : resr.size();
    if (resl.size() > 1 && resr.size() > 1){
      if (abs(resl[resl.size() - 2] - resr[1]) == 2){
        int merge = resl.size() + resr.size() - 1;
        ans = (ans >= merge? ans : merge);
      }
    }
    reverse(resr.begin(), resr.end());
    return make_pair(resl, resr);
  }
public:
  int longestConsecutive(TreeNode* root) {
    if (root ==NULL)
      return 0;
    int maxm = 1;
    dfs(root, maxm);
    return maxm;
  }
};

TreeNode * genT(vector<int> & list){
  TreeNode * root = NULL;
  vector<TreeNode*> l;
  for (int i = 0; i < list.size(); i++){
    if (list[i] == -1)
      continue;
    TreeNode * nt = new TreeNode(list[i]);
    l.push_back(nt);
    if (i == 0){
      root= nt;
    }
    else {
      if (i & 1)
        l[i/2]->left = nt;
      else
        l[i/2-1]->right = nt;
    }
  }
  return root;
}

int main(){
  Solution sol;
  TreeNode * n2 = new TreeNode(2);
  TreeNode * n1 = new TreeNode(1);
  TreeNode * n3 = new TreeNode(3);
  n2->left = n1; n2->right = n3;
  cout << sol.longestConsecutive(n2) << endl; // 3

  TreeNode *l1 = new TreeNode(4);
  TreeNode *l2 = new TreeNode(3);
  TreeNode *l3 = new TreeNode(5);
  TreeNode *l4 = new TreeNode(2);
  TreeNode *l5 = new TreeNode(4);
  TreeNode *l6 = new TreeNode(4);
  TreeNode *l7 = new TreeNode(6);
  TreeNode *l8 = new TreeNode(1);
  l1->left = l2; l1->right = l3;
  l2->left = l4; l2->right = l5;
  l3->left = l6; l3->right = l7;
  l4->left = l8;
  cout << sol.longestConsecutive(l1) << endl; // 6

  TreeNode *r1 = new TreeNode(4);
  TreeNode *r2 = new TreeNode(3);
  r1->right = r2;
  cout << sol.longestConsecutive(r1) << endl; // 2


  TreeNode *b1 = new TreeNode(1);
  TreeNode *b2 = new TreeNode(4);
  TreeNode *b3 = new TreeNode(3);
  TreeNode *b4 = new TreeNode(2);
  b1->left = b2; b1->right = b3;
  b2->left = b4;
  cout << sol.longestConsecutive(b1) << endl; // 1

  vector<int> tree = {19,20,20,19,21,21,19,20,18,20,22,-1,22,-1,20,21,-1,17,-1,-1,21,21,23,21,-1,-1,19,-1,-1,-1,-1,-1,-1,-1,-1,22,22,-1,-1,18,20,21,23,-1,-1,-1,-1,19,-1,-1,-1,-1,24,-1,-1,23,-1,-1,24};
  TreeNode *rt = genT(tree);
  cout << sol.longestConsecutive(rt) << endl;
  return 0;
}
