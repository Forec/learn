#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size() - 1, ans = 0;
		for (int i = 0; i <= j; i++){
			if (nums[i] == val){
				ans++;
				nums[i] = nums[j--];
				i--;
			}
		}
		return nums.size() - ans;
    }
};

int main(){
	vector<int> para = {3, 2, 4, 2, 3, 3, 4, 2, 3};
	Solution sol;
	int ans = sol.removeElement(para, 3);
	cout << ans << endl;
	for (vector<int>::iterator it = para.begin(); it != para.end(); it++){
		cout <<  *it << " ";
	}
	cout << endl;
	return 0;
}
