#include <iostream>
using namespace std;
struct ListNode{
	int val;
	ListNode * next;
	ListNode(int x): val(x), next(NULL){
	}
};

class Solution{
public:
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2){
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;
		ListNode * head = NULL, * tmp1 = NULL, *tmp2 = NULL;
		while (l1 != NULL && l2 != NULL){
			if (l1-> val < l2->val){
				tmp1 = l1;
				l1 = l1->next;
			}
			else{
				tmp1 = l2;
				l2 = l2->next;
			}
			if (head == NULL){
				head = tmp1;
				tmp2 = tmp1;
			}
			else{
				tmp2->next = tmp1;
				tmp2 = tmp1;
			}
		}
		while (l1 != NULL){
			tmp2->next = l1;
			tmp2 = l1;
			l1 = l1->next;
		}
		while (l2 != NULL){
			tmp2->next = l2;
			tmp2 = l2;
			l2 = l2->next;
		}
		return head;
	}
};

int main(){	
	ListNode * l11 = new ListNode(1);
	ListNode * l12 = new ListNode(2);
	ListNode * l13 = new ListNode(6);
	ListNode * l14 = new ListNode(9);
	l11->next = l12; l12->next = l13; l13->next = l14;
	ListNode * l21 = new ListNode(3);
	ListNode * l22 = new ListNode(10);
	ListNode * l23 = new ListNode(13);
	l21->next = l22; l22->next = l23;
	Solution sol;
	ListNode * ans = sol.mergeTwoLists(l11, l21);
	while (ans != NULL){
		cout << ans->val << " " ;
		ans = ans->next;
	}
	cout<< endl;
	return 0;
}
