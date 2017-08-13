#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int searchInsert(vector<int> &nums, int target){
		if (nums.size() == 0)
			return 0;
		int left = 0, right = nums.size() - 1, mid;
		while (left <= right){
			mid = (left + right) / 2;
			if (target == nums[mid])
				return mid;
			if (target < nums[mid]){
				right = mid -1;
			} else {
				left = mid +1;
			}
		}
		if ( target > nums[mid])
			mid++;
		return mid;
	}
};

int main(){
	Solution sol;
	vector<int> para = {1, 5};
	cout << sol.searchInsert(para, 5) << endl;
	cout << sol.searchInsert(para, 2) << endl;
	cout << sol.searchInsert(para, 7) << endl;
	cout << sol.searchInsert(para, 0) << endl;
	return 0;
}
