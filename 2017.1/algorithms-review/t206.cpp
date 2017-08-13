#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head) return NULL;
    ListNode * hd = new ListNode(0);
    hd->next = head;
    ListNode * cur = head, *pre = hd;
    while (cur != NULL){
      ListNode * tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    head->next = NULL;
    delete hd;
    return pre;
  }
};

int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  ListNode *tmp = sol.reverseList(NULL);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
