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
  ListNode * reverseK(ListNode *start, int k){
    ListNode * check = start;
    int count = 0;
    while ((count < k) && check){
      count ++ ;
      check = check->next;
    }
    if (count < k)
      return start;
    ListNode * nextGroupStart = check;
    ListNode * pre = NULL, *cur = start;
    while (cur != nextGroupStart){
      ListNode * tmp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = tmp;
    }
    start->next = reverseK(nextGroupStart, k);
    return pre;
  }
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || !k)
      return head;
    ListNode *h  = head;
    int n =1;
    while (h->next){
      n ++;
      h = h->next;
    }
    k = n - k % n;
    h->next = head;
    for (int i = 0; i < k; i++){
      h = h->next;
    }
    head = h->next;
    h->next = NULL;
    return head;
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
  node1->next = NULL;
  ListNode *tmp = sol.rotateRight(head, 3);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
