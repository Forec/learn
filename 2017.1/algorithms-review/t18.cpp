#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target){
		vector<vector<int>> res;
		int n = nums.size();
		if (n < 4)
			return res;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n - 3; i++){
			if (i > 0 && nums[i] == nums[i-1]) continue;
			if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target)
				break;
			if (nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target)
				continue;
			for (int j = i + 1; j < n - 2; j ++){
				if (j > i + 1 && nums[j] == nums[j-1])
					continue;
				if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target)
					break;
				if (nums[i] + nums[j] + nums[n-2] + nums[n-1] < target)
					continue;
				int left = j+1, right = n - 1;
				while ( left < right){
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if (sum < target)
						left ++;
					else if (sum > target)
						right--;
					else{
						res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
						left++; right--;
						while (nums[left] == nums[left-1] && left < right) left++;
						while (nums[right] == nums[right+1] && left < right) right --;
					}
				}
			}
		}
		return res;
	}
};


int main(){
	Solution sol;
	vector<int> p = {1, 0, -1, 0, -2, 2};
	vector<vector<int>> ans = sol.fourSum(p, 0);
	for (int i= 0; i < ans.size(); i++){
		for (int j = 0 ; j < ans[i].size(); j++){
			cout << ans[i][j] << " " ;
		}
		cout << endl;
	}								  
}
