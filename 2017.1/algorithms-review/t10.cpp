#include <iostream>
using namespace std;

class Solution{
public:
	isMatch(string s, string p){
		if (p.empty())
			return s.empty();
		if ('*' == p[1])
			return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
		else
			return !s.empty() && (s[0] == p[0] || p[0] =='.') && isMatch(s.substr(1), p.substr(1));
	}
};

int main(){
	Solution sol = Solution();
	cout << sol.isMatch("aaabc", "a*bc.*") << endl;
	return 0;
}
