#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0){
			return vector<string>{""};
		}
		vector<string> res;
		for (int m = 0; m < n; m++){
			vector<string> xs = generateParenthesis(m);
			vector<string> rests = generateParenthesis(n - m - 1);
			for (vector<string>::iterator rest = rests.begin(); rest != rests.end(); rest++){
				for (vector<string>::iterator x = xs.begin(); x != xs.end(); x ++){
					res.push_back("(" + (*x) + ")" + (*rest));
				}
			}
		}
		return res;
    }
};

int main(){
	Solution sol;
	vector<string> ans = sol.generateParenthesis(3);
	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << ", " ;
	cout << endl;
	return 0;
}
