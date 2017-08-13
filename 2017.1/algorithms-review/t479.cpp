#include <iostream>
using namespace std;

class Solution {
private:
	long pow(int base, int mi){
		long ans = 1;
		for (int i = 0; i < mi ; i++)
			ans *= base;
		return ans;
	}
	long reverse(long n, int dig){
		long res = 0;
		long ten = pow(10, dig - 1);
		while ( n != 0){
			int d = n % 10;
			res += ten * d;
			ten /= 10;
			n /= 10;
		}
		return res;
	}
public:
    int largestPalindrome(int n) {
        if (n == 1)
			return 9;
		int m = 1337;
		long mod = pow(10, n);
		long max = mod - 1;
		long pro = max * max;
		long right = pro % mod;
		long left = pro / mod;
		cout << left << " " << right << endl;
		if (left == reverse(right, n ))
			return (int)(pro%m);
		if (left > pro)
			left--;
		pro = left * mod + reverse(left, n);
		while (left != mod / 10){
			for (int i = max; i > pro / i; i--){
				if (pro % i == 0)
					return (int)(pro%m);
			}
			left--;
			pro = left * mod + reverse(left, n);
		}
		return (int)(pro % m);
    }
};


int main(){
	Solution sol = Solution();
	cout << sol.largestPalindrome(1) << endl;
	return 0;
}
