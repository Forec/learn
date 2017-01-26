#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int sign = 1, ans = 0, i = 0;
		while (str[i] == ' ' && i < str.length()) i++;
		if (str[i] == '-')
			sign = -1;
		if (str[i] == '+' || str[i] == '-')
			i++;
		while ( i < str.length() && str[i] <= '9' && str[i] >= '0'){
			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && str[i] - '0' > 7)){
				if (sign == 1)
					return INT_MAX;
				else
					return INT_MIN;
			}			
			ans = ans * 10 + str[i++] - '0';
		}
		return ans * sign;
    }
};

int main(){
	Solution sol = Solution();
	cout << sol.myAtoi("   -1239012") << endl;
	return 0;
}
