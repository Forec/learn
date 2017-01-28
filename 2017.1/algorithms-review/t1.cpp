#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> ans;
		ans.clear();
        for (int i = 0; i < nums.size(); i++)
			for (int j = i; j < nums.size(); j++){
				if (i == j)
					continue;
				if (nums[i] + nums[j] == target){
					ans.push_back(i);
					ans.push_back(j);
					return ans;
				}
			}
    }
};

int main(){
	int paras[] = {3, 2, 4};
	vector<int> para(paras, paras + sizeof(paras) / sizeof(int));
	int target = 6;
	Solution sol;
	for (int i: sol.twoSum(para, target)){
		cout << i << " ";
	}
	return 0;
}
