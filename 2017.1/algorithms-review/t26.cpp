#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1)
			return nums.size();
		int i = 0, ans = 0;
		while( i < nums.size()){
			if (i > 0 && nums[i] == nums[i-1]){
				i++;
				ans++;
				continue;
			} else {
				nums[i - ans] = nums[i];
			}
			i++;
		}
		return nums.size() - ans;
	}
};

int main(){
	Solution sol;
	vector<int> para = {1, 1, 1, 2, 3, 4, 4, 5, 6, 7};
	vector<int> para2 = {1, 1, 2};
	cout << sol.removeDuplicates(para) << endl;
	for (vector<int>::iterator it = para.begin(); it != para.end(); it++){
		cout << *it << " " ;
	}
	cout << endl;
	return 0;
}
