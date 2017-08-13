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
  vector<TreeNode*> generate(int left, int right){
    vector<TreeNode*> s;
    if (left > right){
      s.push_back(NULL);
      return s;
    }
    for (int i = left; i <= right; i++){
      vector<TreeNode*> l = generate(left, i-1);
      vector<TreeNode*> r = generate(i+1, right);
      for (int j = 0; j < l.size(); j++){
        for (int k = 0; k < r.size(); k++){
          TreeNode * rt = new TreeNode(i);
          rt->left = l[j];
          rt->right = r[k];
          s.push_back(rt);
        }
      }
    }
    return s;
  }
public:
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0)
      return vector<TreeNode*>();
    return generate(1, n);
  }
};

int main(){
  Solution sol;
  cout << sol.generateTrees(0).size() << endl;
  return 0;
}
