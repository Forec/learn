#include <iostream>
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
	string longestPalindrome(string s) {
		if (s.length() == 0)
			return "";
		char * tmp = new char[s.length() << 1 + 4];
		int * Len = new int[s.length() << 1 + 4];
		tmp[0] = '@';
		for (int i = 1; i <= 2 * s.length(); i+=2){
			tmp[i] = '#';
			tmp[i+1] = s[i / 2];
		}
		tmp[2*s.length() + 1] = '#';
		tmp[2*s.length() + 2] = '$';
		tmp[2*s.length() + 3] = '\0';
		int mx = 0, ans = 0, ansi = 2, p0 = 0;
		for (int i = 1; i <= 2 * s.length() + 1; i++){
			if (mx > i)
				Len[i] = min(mx - i, Len[2 * p0 - i]);
			else
				Len[i] = 1;
			while (tmp[i - Len[i]] == tmp[i + Len[i]])
				Len[i] ++;
			if (Len[i] + i > mx){
				mx = Len[i] + i;
				p0 = i;
			}
			if (Len[i] > ans){
				ans = Len[i];
				ansi = i;
			}
		}
		return s.substr((ansi - ans + 1)/2, ans - 1);
	}
};

int main(){
	Solution sol = Solution();
	string s1 = "abbbba";
	cout << sol.longestPalindrome(s1) << endl;
	return 0;
}
