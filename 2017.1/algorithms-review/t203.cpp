#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode * pre, *tmp, * cur = head;
		pre = new ListNode(0);
		tmp = pre;
		pre->next = head;
		while (cur != NULL){
			if (cur->val == val){
				pre->next = cur->next;
				delete cur;
				cur = pre->next;
			} else {
				cur = cur->next;
				pre = pre->next;
			}
		}
		return tmp->next;
    }
};

int main(){
	ListNode * head = new ListNode(1);
	ListNode * h = head;
	for (int i = 2; i < 7; i++){
		ListNode * tmp = new ListNode(i);
		h->next = tmp;
		h = tmp;
	}
	for (int i = 0; i < 3; i++){
		ListNode * tmp = new ListNode(4);
		h->next = tmp;
		h = tmp;
	}
	for (int i = 8; i < 12; i++){
		ListNode * tmp = new ListNode(i);
		h->next = tmp;
		h = tmp;
	}
	Solution sol;
	ListNode * ans = sol.removeElements(head, 4);
	while (ans != NULL){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
