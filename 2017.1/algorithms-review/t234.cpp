#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    char val;
    ListNode *next;
    ListNode(char x) : val(x), next(NULL) {}
};

class Solution {
private:
  ListNode * reverseList(ListNode * head){
    ListNode * cur = head;
    ListNode * pre = NULL;
    while (cur != NULL) {
      ListNode * tmp = cur->next;
      cur->next = pre;
      pre = cur;
      if (tmp == NULL)
        break;
      cur = tmp;
    }
    return cur;
  }
public:
  bool isPalindrome(ListNode* head) {
    ListNode * fast = head, * slow = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode * half = reverseList(slow);
    while (head != NULL && half != NULL) {
      if (head->val != half->val)
        return false;
      head = head->next;
      half = half->next;
    }
    return true;
  }
};


int main(){
  //  string pal = "abcdfdcba";
  string pal = "";
  ListNode * head = NULL, * last = NULL;
  for (int i = 0; i < pal.length(); i++){
    ListNode *tmp = new ListNode(pal[i]);
    if (last == NULL){
      head = tmp;
    } else {
      last->next = tmp;
    }
    last = tmp;
  }
  Solution sol;
  cout << sol.isPalindrome(head) << endl;
  return 0;
}
