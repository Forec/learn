#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
private:
	ListNode * mergeTwoLists(ListNode * l1, ListNode *l2){
		if(l1 == NULL) return l2;
		if (l2 == NULL) return l1;
		ListNode * head = NULL, * tmp = head;
		while (l1 != NULL && l2 != NULL){
			if (l1-> val < l2->val){
				if (head == NULL){
					head = l1;
					tmp = l1;
				} else {
					tmp->next = l1;
					tmp = l1;
				}
				l1 = l1->next;
			} else{
				if (head == NULL){
					head = l2;
					tmp = l2;
				} else {
					tmp->next = l2;
					tmp = l2;
				}
				l2 = l2->next;
			}
		}
		if (l2 != NULL)
			l1 = l2;
		tmp->next = l1;
		return head;
	}
public:
	ListNode * mergeKLists(vector<ListNode*>& lists){
		if (lists.empty()) return NULL;
		if (lists.size() == 1) return lists[0];
		if (lists.size() == 2) return mergeTwoLists(lists[0], lists[1]);
		ListNode* last = lists.back();
		lists.pop_back();
		return mergeTwoLists(mergeKLists(lists), last); // 这里可以用二分进一步优化
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
	ListNode * l31 = new ListNode(4);
	ListNode * l32 = new ListNode(5);
	ListNode * l33 = new ListNode(16);
	l31->next = l32; l32->next = l33;	
	Solution sol;
	vector<ListNode *> p = {l11, l21, l31};
	ListNode * ans = sol.mergeKLists(p);
	while (ans != NULL){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
