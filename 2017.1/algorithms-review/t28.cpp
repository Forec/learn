#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
	void computeLPSArray(string pat, vector<int>& lps){
		int len = 0;
		lps[0] = 0;
		int i = 1;
		while ( i < pat.length()){
			if (pat[i] == pat[len]){
				len++;
				lps[i] = len;
				i++;
			} else {
				if (len != 0){
					len = lps[len-1];
				} else {
					lps[i] = 0;
					i++;
				}
			}
		}
	}
public:
    int strStr(string haystack, string needle) {
		if (needle.length() > haystack.length() || haystack.length() == 0)
			return -1;
		if (needle.length() == 0)
			return 0;
        vector<int> lps(needle.length(), 0);
		computeLPSArray(needle, lps);
		int i = 0, j = 0;
		while ( i < haystack.length()){
			if (haystack[i] == needle[j]){
				j++;
				i++;
			}
			if ( j == needle.length()){
				return i -j;
			} else if (i < haystack.length() && haystack[i] != needle[j]){
				if (j != 0)
					j = lps[j-1];
				else
					i++;
			}
		}
		return -1;
    }
};

int main(){
	Solution sol;
	cout << sol.strStr("", "") << endl;
	return 0;
}
