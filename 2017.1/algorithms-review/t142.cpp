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
  ListNode* detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast){
        slow = head;
        while (fast != slow){
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return NULL;
  }
};


int main(){
  Solution sol;
  ListNode *head = new ListNode(1);
  ListNode * node1 = new ListNode(2);
  ListNode *node2 = new ListNode(3);
  head->next = node1;
  node1->next = node2;
  node2->next = head;
  cout << (sol.detectCycle(head) == NULL?-1:sol.detectCycle(head)->val) << endl;
  return 0;
}
