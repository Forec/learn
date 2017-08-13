#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findPosisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.size() == 0)
			return 0;
		int maxTP = timeSeries[0] + duration, ans = duration;
		for (int i = 0; i < timeSeries.size(); i++){
			int targetTP = timeSeries[i] + duration;
			if (timeSeries[i] > maxTP)
				ans += duration;
			else
				ans += targetTP - maxTP;
			maxTP = targetTP;
		}
		return ans;
    }
};


int main(){
	Solution sol;
	vector<int> para = {1, 3, 8};
	cout << sol.findPosisonedDuration(para, 4) << endl;
	return 0;
}
