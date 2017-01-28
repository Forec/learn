#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	int abs(int x){
		return x < 0 ? -x : x;
	}
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
		int  best = nums[0] + nums[1] + nums[2], minc = abs(best - target);
		bool hasPerfect = false;
		for (int i = 0; i < nums.size(); i++){
			int targetp = target-nums[i];
			int front = i + 1;
			int back = nums.size() - 1;
			while (front < back){
				int sum = nums[front] + nums[back];
				if (sum < targetp){
					if (targetp - sum < minc){
						minc = targetp - sum;
						best = nums[i] + sum;
					}
					front ++;
				}
				else if (sum > targetp){
					if (sum - targetp < minc){
						minc = sum - targetp;
						best = nums[i] + sum;
					}
					back --;
				}
				else{
					hasPerfect = true;
					minc = 0;
					best = nums[i] + targetp;
					break;
				}
			}
			if (hasPerfect)
				break;
			while ( i + 1 < nums.size() && nums[i+1] == nums[i])
				i++;
		}
		return best;
    }
};

int main(){
	int p[] = {6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10};
	vector<int> para(p, p + sizeof(p) / sizeof(int));
	Solution sol = Solution();
	cout << sol.threeSumClosest(para, -52);
	return 0;
}
