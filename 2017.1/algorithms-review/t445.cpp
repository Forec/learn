#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    stack<int> s1, s2;
    while (l1){
      s1.push(l1->val);
      l1 = l1->next;
    }
    while(l2){
      s2.push(l2->val);
      l2 = l2->next;
    }
    ListNode * head = NULL;
    int cn = 0;
    while (!s1.empty() || !s2.empty() || cn){
      int sum = cn + (!s1.empty() ? s1.top() : 0) + (!s2.empty() ? s2.top() : 0);
      if (!s1.empty()){
        s1.pop();
      }
      if (!s2.empty()){
        s2.pop();
      }
      ListNode * tmp = new ListNode(sum % 10);
      tmp->next = head;
      head = tmp;
      cn = sum / 10;
    }
    return head;
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
  ListNode*tmp =sol.addTwoNumbers(head, head);
  while (tmp){
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
