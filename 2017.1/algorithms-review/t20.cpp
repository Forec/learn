#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        char * stack = new char[s.length()];
		int top = 0;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				stack[top++] = s[i];
			else if (s[i] == ')'){
				if (top > 0 && stack[top-1] == '(')
					top--;
				else
					return false;
			} else if (s[i] == ']'){
				if (top > 0 && stack[top-1] == '[')
					top--;
				else
					return false;
			} else {
				if (top > 0 && stack[top-1] == '{')
					top--;
				else
					return false;
			}
		}
		if (top == 0)
			return true;
		return false;
    }
};

int main(){
	Solution sol;
	cout << sol.isValid("()[(())]");
	return 0;
}
