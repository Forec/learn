#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<int> searchRange(vector<int> & nums, int target){
		if (nums.size() == 0)
			return vector<int>(2, -1);
		int left = 0, right = nums.size() - 1, mid = 0, temp, midtemp;
		while (left <= right){
			mid = (left + right) / 2;
			if (nums[mid] == target)
				break;
			if (nums[mid] < target){
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
		if (nums[mid] != target){
			return vector<int>(2, -1);
		}
		temp = mid - 1; left = 0;
		while (left < temp){
			midtemp = (left + temp) /2;
			if (nums[midtemp] == target){
				temp = midtemp - 1;
			} else {
				left = midtemp + 1;
			}
		}
		temp = mid + 1; right = nums.size() - 1;
		while (temp < right){
			midtemp = (temp + right) / 2;
			if (nums[midtemp] == target){
				temp = midtemp + 1;
			} else {
				right = midtemp - 1;
			}
		}
		if (nums[left] != target)
			left++;
		if (nums[right] != target)
			right --;
		vector<int> ans = {left, right};
		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> para = {1, 4};
	vector<int> ans = sol.searchRange(para, 4);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
