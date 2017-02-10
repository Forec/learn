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
private:
  ListNode * insert(ListNode * head, ListNode* ins){
    if (head == NULL){
      return ins;
    }
    ListNode * pre = new ListNode(0);
    pre->next = head;
    ListNode * ls=pre;
    while (ls && ls->next && ls->next->val < ins->val)
      ls=ls->next;
    ins->next = ls->next;
    ls->next = ins;
    ls = pre->next;
    delete pre;
    return ls;
  }
public:
  ListNode* insertionSortList(ListNode* head) {
    ListNode * tmp = head;
    ListNode *h  =NULL;
    while (tmp){
      ListNode *nes = tmp->next;
      tmp->next = NULL;
      h = insert(h, tmp);
      tmp = nes;
    }
    return h;
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
  ListNode *tmp = sol.insertionSortList(head);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
