#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.length() == 0){
			return 0;
		}
        int* m = new int[s.length()];
		bool inBefore;
		int tempJ;
		m[0] = 1;
		for (int i = 1; i < s.length(); i++){
			inBefore = false;
			tempJ = i-1;
			for (int j = i - 1; j > i - 1 - m[i-1]; j--){
				if (s[j] == s[i]){
					inBefore = true;
					tempJ = j;
					break;
				}
 			}
			if (!inBefore){
				m[i] = m[i-1] + 1;
			} else {
				m[i] = i - tempJ;
			}
		}
		int ans = m[0];
		for (int i = 1; i < s.length(); i++)
			if (ans < m[i])
				ans = m[i];
		delete []m;
		return ans;
    }
};

int main(){
	string s1 = "abcabcbb";
	string s2 = "bbbbb";
	string s3 = "pwwkew";
	string s4 = "";
    Solution sol = Solution();
	cout << sol.lengthOfLongestSubstring(s1) << " " <<
		sol.lengthOfLongestSubstring(s2) << " " <<
		sol.lengthOfLongestSubstring(s3) << " " <<
		sol.lengthOfLongestSubstring(s4) << endl;
	return 0;
}
