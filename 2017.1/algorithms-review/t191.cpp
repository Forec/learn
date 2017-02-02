#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ans = 0;
        for (int i = 0; i < 32; i++){
			ans += (n&1);
			n >>= 1;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.hammingWeight(16) << endl;
	return 0;
}
