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

class BSTIterator {
private:
  vector<TreeNode *> up;
  TreeNode *cur;
public:
  BSTIterator(TreeNode *root) {
    cur = root;
    up.clear();
    while (cur != NULL){
      up.push_back(cur);
      cur = cur->left;
    }
  }
  bool hasNext() {
    if (up.size() > 0)
      return true;
    else if (cur != NULL && cur->right != NULL)
      return true;
    else
      return false;
  }
  int next() {
    if (cur == NULL || cur->right == NULL){
      cur = up.back();
      up.pop_back();
    } else if (cur->right != NULL){
      cur = cur->right;
      while (cur != NULL){
        up.push_back(cur);
        cur = cur->left;
      }
      cur = up.back();
      up.pop_back();
    }
    return cur->val;
  }
};

int main (){
  TreeNode *n5 = new TreeNode(5);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n6 = new TreeNode(6);
  TreeNode *n7 = new TreeNode(7);
  n5->left = n3; n5->right = n7;
  n7->left = n6; n3->right = n4;
  n3->left = n2; n2->left = n1;
  BSTIterator i = BSTIterator(n5);
  while (i.hasNext())
    cout << i.next() << " ";
  return 0;
}
