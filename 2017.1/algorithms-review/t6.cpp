#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int round;
		if (numRows == 1)
			return s;
		else if (numRows == 2){
			string ans = "";
			for (int i = 0; i < s.length(); i+=2)
				ans.push_back(s[i]);
			for (int i = 1; i < s.length(); i+=2)
				ans.push_back(s[i]);
			return ans;
		}
		else
			round = numRows * (numRows-1) - (numRows-2) * (numRows-1);
		// 除了第一行和最后一行是一个，其它每行都是两个。
		string firstLine = "", lastLine = "";
		for (int i = 0; i < s.length(); i += round){
			firstLine.push_back(s[i]);
			if (i + numRows - 1 < s.length())
				lastLine.push_back(s[i+numRows-1]);
		}
		string ans = firstLine;
		for (int j = 1; j < numRows - 1; j ++){  // 中间几行
			string temp = "";
			for (int i = j; i < s.length(); i += round){
				temp.push_back(s[i]);
				int tmpAnother = i + 2*(numRows - (i % round+1));
				if (tmpAnother < s.length())
					temp.push_back(s[tmpAnother]);
			}
			ans += temp;
		}
		ans += lastLine;
		return ans;
    }
};

int main(){
	Solution sol = Solution();
	cout << sol.convert("PAYPALISHIRING", 1) << endl;
	return 0;
}
