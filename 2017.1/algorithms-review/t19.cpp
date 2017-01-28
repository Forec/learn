#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){
	}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<ListNode*> temp;
		temp.clear();
		ListNode * p = head;
		while ( p != NULL){
			temp.push_back(p);
			p = p->next;
		}
		ListNode *toDelete = temp[temp.size() - n];
		if ( n == temp.size() ){
			return head->next;
		} else {
			ListNode * pre = temp[temp.size() - n - 1];
			pre->next = toDelete->next;
			toDelete->next = NULL;
			delete toDelete;
			return head;
		}
    }
};

int main(){
	ListNode * head = new ListNode(1);
	ListNode * h = head;
	for (int i = 2; i <= 5; i++){
		ListNode * temp = new ListNode(i);
		h->next = temp;
		h = temp;
	}
	Solution sol = Solution();
	ListNode * ans = sol.removeNthFromEnd(head, 5);
	while (ans != NULL){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
