#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int length1 = 0, length2 = 0;
	    ListNode *t;
		t = l1;
		while (t != NULL){
			length1 ++;
			t = t->next;
		}
		t = l2;
		while (t != NULL){
			length2 ++;
			t = t->next;
		}
		int* data1 = new int[length1 + 1];
		int *data2 = new int[length2 + 1];
		int *ans = new int[(length1 > length2 ? length1 : length2) + 2];
		ans[0] = 0;
		int i = 0, j = 0;
		t = l1;
		while (t != NULL){
			data1[i++] = t->val;
			t = t->next;
		}
		i = 0; t = l2;
		while (t != NULL){
			data2[i++] = t->val;
			t = t->next;
		}
		int c_in = 0, index = 0, temp = 0;
		i = 0; j = 0;
		while (i < length1 && j < length2){
			temp = data1[i] + data2[j] + c_in;
			i++; j++;
			if (temp > 9){
				temp -= 10;
				c_in = 1;
			} else
				c_in = 0;
			ans[index++] = temp;
		}
		while (i < length1){
			temp = data1[i] + c_in;
			i++;
			if (temp > 9){
				temp -= 10;
				c_in = 1;
			} else
				c_in = 0;
			ans[index++] = temp;
		}
		while (j < length2){
			temp = data2[j] + c_in;
			j++;
			if (temp > 9){
				temp -= 10;
				c_in = 1;
			} else
				c_in = 0;
			ans[index++] = temp;
		}
		if (c_in == 1){
			ans[index++] = 1;
		}
		delete[] data1;
		delete[] data2;
		ListNode *head = new ListNode(ans[0]);
		ListNode *res = head;
		i = 1;
		while (i < index){
			ListNode *temp = new ListNode(ans[i++]);
			head->next = temp;
			head = temp;
		}
		delete[] ans;
		return res;
    }
};

int main(){
	Solution sol = Solution();
	ListNode * Para11 = new ListNode(1);
	ListNode * Para12 = new ListNode(9);
	//	ListNode * Para13 = new ListNode(3);
	Para11->next = Para12; //Para12->next = Para13;

	ListNode * Para21 = new ListNode(9);
	//	ListNode * Para22 = new ListNode(0);
	//	ListNode * Para23 = new ListNode();
	//	Para21->next = Para22; Para22->next = Para23;

	ListNode * ans = sol.addTwoNumbers(Para11, Para21);
	while (ans != NULL){
		cout << ans->val << " ";
		ans = ans->next;
	}
	return 0;
}
