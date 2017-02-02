#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
private:
	string base;
	set<int> res;
	void swap(string &x, string &y){
		string tmp = x;
		x = y;
		y = tmp;
	}
	void calcLPS(vector<int> &lps, string& str){
		int len = 0;
		int i = 1;
		lps[0] = 0;
		while ( i < str.length()){
			if (str[i] == str[len]){
				len++;
				lps[i] = len;
				i++;
			} else {
				if (len == 0){
					lps[i] = 0;
					i++;
				} else {
					len = lps[len-1];
				}
			}
		}
	}
	vector<int> strStr(string & str){
		vector<int> lps(str.length(), 0);
		vector<int> ans;
		ans.clear();
		calcLPS(lps, str);
		int i = 0, j = 0;
		while ( i < base.length()){
			if (base[i] == str[j]){
				i++;
				j++;
			}
			if ( j == str.length()){
				ans.push_back(i - j);
				j = lps[j-1];
			} else if ( i < base.length() && base[i]!=str[j]){
				if (j != 0)
					j = lps[j-1];
				else
					i++;
			}
		}
		return ans;
	}
	void dfs(vector<string> &build, int k){
		if (k == build.size()){
			string buildString = "";
			for (int i = 0; i < k; i ++){
				buildString += build[i];
			}
			vector<int> ans = strStr(buildString);
			for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
				res.insert(*it);
			}
			return;
		}
		for (int i = k; i < build.size(); i++){
			swap(build[k], build[i]);
			dfs(build, k+1);
			swap(build[k], build[i]);
		}
	}
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> vres;
		vres.clear();
        res.clear();
		int basic = 0;
		for (vector<string>::iterator it = words.begin(); it != words.end(); it++){
			basic += it->length();
		}
		if (basic > s.length())
			return vres;
		if (words.size() == 0){
			for (int i = 0; i < s.length(); i++){
				vres.push_back(i);
			}
			return vres;
		}
		base = s;
		dfs(words, 0);
		for (set<int>::iterator it = res.begin(); it != res.end(); it++)
			vres.push_back(*it);
		return vres;
    }
};

int main(){
	Solution sol;
	vector<string> para = {"foo", "bar"};
	vector<string> para2 = {};
	vector<int> ans = sol.findSubstring("barfoothefoobarman", para);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}
