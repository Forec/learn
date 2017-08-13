#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  void dfs(TreeNode * root){
    if (root == NULL)return;
    cout <<root->val << " ";
    dfs(root->left);
    dfs(root->right);
  }
  TreeNode* str2tree(string s) {
    if (s.length() == 0)
      return NULL;
    int i = 0;
    while (i < s.length() && s[i] != '('){
      i++;
    }
    stringstream ss;
    int val;
    ss << s.substr(0, i);
    ss >> val;
    TreeNode * node = new TreeNode(val);
    if (i < s.length()){
      s = s.substr(i);
      int cuo = 1, j =1;
      while (j < s.length() && cuo != 0){
        if (s[j] == '(')
          cuo ++;
        if (s[j] == ')')
          cuo--;
        j++;
      }
      node->left = str2tree(s.substr(1, j-2));
      if (j +1 < s.length() && s.length() - j - 2 > 0)
        node->right = str2tree(s.substr(j+1, s.length() - j - 2));
    }
    return node;
  }
};

int main(){
  Solution sol;
  TreeNode *rt = sol.str2tree("4(2(3)(1(-2)(6(-2)(4))))(-6(-5))");
  sol.dfs(rt);
  cout << endl;
  return 0;
}
