#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class myComparision{
	bool reverse;
public:
	myComparision(const bool & revparam = false){
		reverse = revparam;
	}
	bool operator() (const ListNode *lhs, const ListNode *rhs) const{
		if (reverse)
			return (lhs->val < rhs->val);
		else
			return lhs->val > rhs->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
			return NULL;
		priority_queue<ListNode*, vector<ListNode*>, myComparision> pq;
		ListNode * head = new ListNode(0);
		ListNode * tail = head; 
		for (ListNode * node: lists){
			if (node != NULL)
				pq.push(node);
		}
		while (!pq.empty()){
			tail->next = pq.top();
			pq.pop();
			tail = tail->next;
			if (tail->next != NULL)
				pq.push(tail->next);
		}
		return head->next;
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
