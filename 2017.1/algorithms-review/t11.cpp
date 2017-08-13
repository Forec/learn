#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	int min(int x, int y){
		return x < y ? x : y;
	}
    int max(int x, int y){
        return x > y ? x : y;
    }
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
		int i = 0, j = height.size() - 1;
		while ( i < j ){
			ans = max(ans, (j-i) * min(height[i], height[j]));
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
        return ans;
    }
};

int main(){
	int para[] = {1,2,3,4,5,6};
	vector<int> p(para, para + sizeof(para) / sizeof(int));
	Solution sol = Solution();
	cout << sol.maxArea(p) << endl;
	return 0;
}
