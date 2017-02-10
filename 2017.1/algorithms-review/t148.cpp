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
  ListNode * merge(ListNode * head1, ListNode *head2){
    if (head1==NULL) return head2;
    if (head2==NULL) return head1;
    ListNode * l1 = head1, *l2 = head2;
    ListNode * hh = new ListNode(0);
    ListNode * pre = hh;
    while (l1 && l2){
      if (l1->val < l2->val){
        pre->next = l1;
        l1 = l1->next;
      } else {
        pre->next = l2;
        l2 = l2->next;
      }
      pre = pre->next;
    }
    while (l1){
      pre->next = l1;
      l1 = l1->next;
      pre = pre->next;
    }
    while (l2){
      pre->next = l2;
      l2 = l2->next;
      pre = pre->next;
    }
    ListNode * ans = hh->next;
    delete hh;
    return ans;
  }
public:
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * fast = head, *slow = head;
    while (fast && fast->next &&fast->next->next){
      fast = fast->next->next;
      slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode *left = sortList(head), *right = sortList(fast);
    return merge(left, right);
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
  ListNode *tmp = sol.sortList(head);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
