#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> p;
		int ans = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '('){
				p.push_back(0);
				continue;
			}
			int right = 1;
			int j = i - 1, max = 0;
			while (j >= -1){
				if (right == 0){
					if (i - j > max){
						max = i - j;
					}
				}
				if (j == -1)
					break;
				if (p[j] != 0){
					j -= p[j];
					continue;
				}
				if (s[j] == '('){
					right --;
					if (right < 0)
						break;
				} else {
					right ++;
				}
				j--;
			}
			p.push_back(max);
			if (max > ans)
				ans = max;
		}
		// for (int i = 0; i < s.length(); i++){
		// 	cout << s[i] << "  ";
		// }
		// cout << endl;
		// for (vector<int>::iterator it = p.begin(); it != p.end(); it++){
		// 	cout << *it << (*it < 10 ? "  " : " ");
		// }
		// cout << endl;
		return ans;
    }
};

int main(){
	Solution sol;
	cout << sol.longestValidParentheses("()()") << endl;
	cout << sol.longestValidParentheses("") << endl;
	string para = "(((()))()()(()";
	cout << para.length() << endl;
	cout << sol.longestValidParentheses(para) << endl;	
	return 0;
}
