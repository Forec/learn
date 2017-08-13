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
	ListNode *reverseKGroup(ListNode *head, int k){
		if (head == NULL || k <= 0)
			return NULL;
		if (head->next == NULL || k == 1)
			return head;
		int count = 0;
		ListNode *curHead = head, *curPre = head, *curTail = head, *tmp = NULL, *index = head;
		ListNode *totalHead = NULL;
		bool first = true;
		while (index != NULL){
			count++;
			index = index->next;
			if (count == k){
				break;
			}
		}
		if (count < k){
			return head;
		}
		count = 0;
		index = head->next;
		while(index != NULL){
			curHead = index;
			tmp = index->next;
			curHead->next = curPre;
			curPre = curHead;
			index = tmp;
			count++;
			if (count == k-1){
				if (first){
					totalHead = curHead;
					first = false;
				}
				curHead = index;
				curPre = index;
				count = 1;
				tmp = index;
				while (index != NULL){
					index = index->next;
					if (index != NULL)
						count ++;
					if (count == k)
						break;
				}
				if (count < k){
					curTail->next = tmp;
					return totalHead;
				}
				curTail->next = index;
				count = 0;
				index = tmp;
				if (index == NULL){
					return totalHead;
				}
				else{
					curTail = index;
					index = index->next;
				}
			}
		}
		return totalHead;
	}
};

int main(){
	ListNode * head = new ListNode(1);
	ListNode * h = head;
	for (int i = 2; i <= 13; i++){
		ListNode * temp = new ListNode(i);
		h->next = temp;
		h = temp;
	}
	head->next = NULL;
	Solution sol = Solution();
	ListNode *ans = sol.reverseKGroup(head, 1);
	while (ans != NULL){
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
