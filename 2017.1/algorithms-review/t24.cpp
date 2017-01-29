#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){
	}
};

class Solution{
public:
	ListNode * swapPairs(ListNode * head){
		if (head == NULL)
			return NULL;
		if (head->next == NULL)
			return head;
		ListNode *h1 = head, *res = head->next, *temp = NULL;
		ListNode *h2 = new ListNode(0);
		h2->next = head;
		while (h2 != NULL && h1 != NULL && h1->next != NULL){
			h2->next = h1->next;
			temp = h1->next->next;
			h1->next->next = h1;
			h1->next = temp;
			h2 = h1;
			h1 = h1->next;
		}
		return res;
	}
};

int main(){
	ListNode * head = new ListNode(1);
	ListNode * h = head;
	// for (int i = 2; i <= 5; i++){
	// 	ListNode * temp = new ListNode(i);
	// 	h->next = temp;
	// 	h = temp;
	// }
	Solution sol = Solution();
	ListNode * ans = sol.swapPairs(head);
	while (ans != NULL){
		cout << ans->val << " " ;
		ans = ans->next;
	}
	return 0;
}
