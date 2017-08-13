#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return -1;
        int left = 0, right = nums.size() - 1;
		while (left < right){
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[left] <= nums[mid]){
				if (target >= nums[left] && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			} else {
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			}
		}
		return nums[left] == target ? left : -1;
    }
};

int main(){
	vector<int> para = {5, 5, 5, 1, 3, 5};
	Solution sol;
	cout << sol.search(para, 5) << endl;
	return 0;
}
