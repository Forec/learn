#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        int minlen = strs[0].length();
        for (int i = 1; i < strs.size(); i++)
            minlen = minlen > strs[i].length() ? strs[i].length() : minlen;
		if (minlen == 0)
			return "";
        bool flag = true;
        for (int i = 0; i < minlen; i++){
            char code = strs[0][i];
            for (int j = 0; j < strs.size(); j++)
                if (strs[j][i] != code) {
                    flag = false;
                    break;
                }
            if (!flag){
                return strs[0].substr(0, i);
            }
        }
		return strs[0].substr(0, minlen);
    }
};

int main(){
	vector<string> strs;
	strs.push_back("dfuck");
	strs.push_back("afutest");
	strs.push_back("cfucfdk");
	strs.clear();
	strs.push_back("a");
	Solution sol = Solution();
	cout << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
