#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	string dicts[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
		if (digits == "")
			return res;
		res.push_back("");
		for (int i = 0 ; i < digits.length(); i ++){
			string num_chars = dicts[digits[i] - '0'];
			vector<string> temp;
			temp.clear();
			for (int j = 0; j < num_chars.length(); j++)
				for (int k = 0; k < res.size(); k++)
					temp.push_back(res[k] + num_chars[j]);
			res = temp;
		}
		return res;
    }
};

int main(){
	Solution sol = Solution();
	vector<string> ans = sol.letterCombinations("");
	cout << ans.size();
	cout << endl;
	return 0;
}
