#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        while (node != NULL){
			if (node->next != NULL){
				node->val = node->next->val;
				if (node->next->next == NULL){
					node->next = NULL;
				}
			}
			node = node->next;
		}
    }
};

int main(){
	ListNode * head = new ListNode(1);
	ListNode * h = head, * p;
	for (int i = 2 ; i < 10; i++){
		ListNode * tmp = new ListNode(i);
		if (i == 4)
			p = tmp;
		h->next = tmp;
		h = tmp;
	}
	Solution sol;
	sol.deleteNode(p);
	while (head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
	return 0;
}
