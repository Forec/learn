#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
			return false;
		int p = x, q = 0;
		while ( p >= 10){
			q *= 10;
			q += p%10;
			p /= 10;
		}
		return q == x / 10 && p == x % 10;
    }
};

int main(){
	int test = 99399;
	Solution sol = Solution();
	cout << sol.isPalindrome(test) << endl;
	return 0;
}
