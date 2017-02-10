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
  ListNode* partition(ListNode* head, int x) {
    ListNode * hh = new ListNode(0);
    ListNode * rr = new ListNode(0);
    hh->next = head; rr->next = head;
    ListNode * pre = hh, * cur = head, * last = rr;
    while (cur){
      if (cur->val < x){
        last->next = cur->next;
        cur->next= NULL;
        pre->next = cur;
        pre = cur;
        cur = last->next;
      } else{
        last = cur;
        cur = cur->next;
      }
    }
    pre->next = rr->next;
    delete rr;
    ListNode * tmp = hh->next;
    delete hh;
    return tmp;
  }
};

int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(3);
  ListNode *node2 = new ListNode(2);
  ListNode * node3 = new ListNode(5);
  ListNode * node4 = new ListNode(4);
   head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode*tmp =sol.partition(head, 4);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
