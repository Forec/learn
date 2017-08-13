#include <iostream>
#include <unordered_set>
#include <vector>
#include <unordered_map>
#include <stack>
#include <algorithm>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode * h = head;
    while(h){
      RandomListNode *tmp = new RandomListNode(h->label);
      tmp->next = h->next;
      h->next = tmp;
      h = tmp->next;
    }
    h = head;
    while (h){
      //      cout << head->label <<" " << endl;
      h->next->random = (h->random == NULL? NULL:h->random->next);
      h = h->next->next;
    }
    RandomListNode * res= (head == NULL ? NULL :head->next);
    h = head;
    while(h){
      RandomListNode *tmp = h->next;
      h->next = h->next->next;
      tmp->next = (h->next == NULL ? NULL:h->next->next);
      h = h->next;
    }
    return res;
  }
};

int main(){
  Solution sol;
  RandomListNode *head = new RandomListNode(1);
  RandomListNode * node1 = new RandomListNode(2);
  RandomListNode *node2 = new RandomListNode(3);
  RandomListNode * node3 = new RandomListNode(4);
  RandomListNode * node4 = new RandomListNode(5);
   head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  RandomListNode*tmp =sol.copyRandomList(head);
  while (tmp){
    cout << tmp->label << " ";
    tmp = tmp->next;
  }
  cout << endl;
  return 0;
}
