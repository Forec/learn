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
    while (t){
      if (t->next != NULL && t->next->val == t->val){
        ListNode* tmp = t->next;
        t->next=  tmp->next;
        delete tmp;
        continue;
      }
      t = t->next;
    }
    return head;
  }
};

int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(1);
  ListNode *node2 = new ListNode(1);
  head->next = node1;
  node1->next = node2;
  sol.deleteDuplicates(head);
  ListNode *tmp = head;
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
