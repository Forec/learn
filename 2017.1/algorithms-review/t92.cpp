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
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == NULL) return NULL;
    ListNode * hh = new ListNode(0);
    hh->next = head;
    ListNode * l1 = head, * l2 = head, *pre = hh;
    int c1 = 1, c2 = 1;
    while ((c1++ < m) && l1){
      pre = l1;
      l1 = l1->next;
    }
    while ((c2++ < n) && l2){
      l2 = l2->next;
    }
    ListNode *tmp = l2->next;
    l2->next = NULL;
    pre->next = reverseList(l1);
    l1->next = tmp;
    ListNode *ans = hh->next;
    delete hh;
    return ans;
  }
};

int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  ListNode * node3 = new ListNode(4);
  ListNode * node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  ListNode *tmp = sol.reverseBetween(NULL, 2, 4);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
