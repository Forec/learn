#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
	long long perm2num(vector<int> & p){
		long long num = 0, add = 1, n = p.size();  
		for (long long i = n - 2; i >= 0; i--){
			for (long long j = i + 1; j < n; j++)  
				if ( p[j] <= p[i] ) 
					num += add;
			add *= (n - i);
		}
		return num; 
	}
	void num2perm(long long num, vector<int> &p){
		sort(p.begin(), p.end());
		vector<int> b(p);
		long long n = p.size();
		for (long long i = n - 1; i >= 0; i--){
			p[i] = num % (n - i);
			num /= (n - i);
		}
		for (long long i = n - 1; i >= 0; i--){
			for (long long j = i - 1; j >= 0; j--)
				if (p[j] <= p[i])
					p[i]++;
		}
		for (long long i = 0; i < n; i++)
			p[i] = b[p[i]];
	}
	long long factorial(long long n){
		long long base = 1;
		for (long long i = 2; i <= n; i++){
			base *= i;
		}
		return base;
	}
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
		long long upper = factorial(size);
		long long cur = perm2num(nums);
		if (upper-1 > cur){
			num2perm(cur+ 1, nums);
		} else {
			num2perm(0, nums);
		}
    }
};

int main(){
	vector<int> para1 = {3,2,20,16,1,15,15,14,27,26,5,16,9,13,17,24,15,12,15,14,27,14,14,3,20,7,18,6,8,8,24,3,11,14,19,12,0,26,18,19,22,16,6,24,29,15,10,14,28,17,21,17,2,27,12,22};
	Solution sol;
	sol.nextPermutation(para1);
	for (vector<int>::iterator it = para1.begin(); it != para1.end(); it++){
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
