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
  ListNode * reverse(ListNode * head){
    ListNode * pre = NULL;
    ListNode *h  =head;
    while (h){
      ListNode * tmp = h->next;
      h->next = pre;
      pre = h;
      h = tmp;
    }
    return pre;
  }
public:
  void reorderList(ListNode* head) {
    if (!head)return;
    ListNode * fast = head, * slow = head;
    while(fast && fast->next && fast->next->next){
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode *right = slow->next;
    slow->next = NULL;
    right = reverse(right);
    fast = head;
    while (fast && right){
      ListNode * tmp = fast->next;
      fast->next = right;
      ListNode *tmpr = right->next;
      right->next = tmp;
      right = tmpr;
      fast = tmp;
    }
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
  head->next = NULL;
  sol.reorderList(head);
  ListNode*tmp = head;
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
