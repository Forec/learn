#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode * build(ListNode *start, ListNode * end){
    if (start == end)
      return NULL;
    ListNode* fast = start, * slow = start;
    while (fast != end && fast->next != end){
      fast = fast->next->next;
      slow = slow->next;
    }
    TreeNode * node = new TreeNode(slow->val);
    node->left = build(start, slow);
    node->right = build(slow->next, end);
    return node;
  }
public:
  TreeNode* sortedListToBST(ListNode* head) {
    return build(head, NULL);
  }
  void dfs(TreeNode *root){
    if (!root) return;
    cout << root->val << endl;
    dfs(root->left);
    dfs(root->right);
  }
};

int main(){
  Solution sol;
  ListNode * start = new ListNode(1), *head = start;
  for (int i = 2; i < 5; i ++){
    ListNode * temp = new ListNode(i);
    head->next = temp;
    head = temp;
  }
  TreeNode * ans = sol.sortedListToBST(start);
  sol.dfs(ans);
  return 0;
}
