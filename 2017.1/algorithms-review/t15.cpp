#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;
        sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++){
			int target = -nums[i];
			if (target < 0)  // 因为是已经排好序的数组，一旦有 -nums[i] < 0，则 nums[i] > 0，需要 nums[j] + nums[k] == nums[i]，因为nums[i] < nums[j] < nums[k] 所以不可能。
				break;
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back){
				int sum = nums[front] + nums[back];
				if (sum < target)
					front ++;
				else if (sum > target)
					back --;
				else{
					vector<int> triplet(3, 0);
					triplet[0] = nums[i];
					triplet[1] = nums[front];
					triplet[2] = nums[back];
					res.push_back(triplet);
					while (front < back && nums[front] == triplet[1]) front ++;
					while (front < back && nums[back] == triplet[2]) back--;
				}
			}
			while ( i + 1 < nums.size() && nums[i+1] == nums[i])
				i++;
		}
		return res;
    }
};

int main(){
	int p[] = {-2, 4, -5, -6, -23, 1, -3 ,5, 8};
	vector<int> para(p, p + sizeof(p) / sizeof(int));
	Solution sol = Solution();
	vector<vector<int>> ans = sol.threeSum(para);
	for (int i = 0; i < ans.size(); i ++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " " ;
		}
		cout << endl;
	}
	return 0;
}
