#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
        int left = 0, right = nums.size() - 1;
		while (left < right){
			int mid = (left + right) / 2;
			if (nums[mid] == target)
				return true;
			if (nums[right] < nums[mid]){
				if (target >= nums[left] && target < nums[mid])
					right = mid - 1;
				else
					left = mid + 1;
			} else if (nums[right] > nums[mid]){
				if (target > nums[mid] && target <= nums[right])
					left = mid + 1;
				else
					right = mid - 1;
			} else {
				right --;
			}
		}
		return nums[left] == target ? true : false;
    }
};

int main(){
	vector<int> para = {3, 1};
	Solution sol;
	cout << sol.search(para, 1) << endl;
	return 0;
}
