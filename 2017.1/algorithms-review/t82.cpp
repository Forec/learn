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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode * t = head;
    ListNode * pre = new ListNode(-1);
    pre->next = head;
    ListNode *first = pre;
    while (t){
      bool single = true;
      while (t->next != NULL && t->next->val == t->val){
        single = false;
        ListNode* tmp = t->next;
        t->next=  tmp->next;
        delete tmp;
      }
      if (!single){
        ListNode *tmp = t;
        t = t->next;
        pre->next = t;
        delete tmp;
        continue;
      }
      pre = t;
      t = t->next;
    }
    return first->next;
  }
};

int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(1);
  ListNode *node2 = new ListNode(1);
  head->next = node1;
  node1->next = node2;
  ListNode *tmp = sol.deleteDuplicates(head);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
