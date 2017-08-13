#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	void dfs(TreeNode *root, map<int, int> &dict){
		if (root == NULL)
			return;
	    if (root->left != NULL){
			dfs(root->left, dict);
		}
		if (root->right != NULL){
			dfs(root->right, dict);
		}
		if (dict.count(root->val) == 0){
			dict[root->val] = 1;
		} else {
			dict[root->val] += 1;
		}
	}
public:
    vector<int> findMode(TreeNode* root) {
		vector<int> ans;
        map<int, int> dict;
		dfs(root, dict);
		int maxt = 0;
		for (map<int, int>::iterator it = dict.begin(); it != dict.end(); it++){
			if (it->second > maxt){
				maxt = it->second;
				ans.clear();
				ans.push_back(it->first);
			} else if (it->second == maxt){
				ans.push_back(it->first);
			}
		}
		return ans;
    }
};



int main(){
	TreeNode * root = new TreeNode(1);
	root->left = NULL;
	TreeNode *right = new TreeNode(2);
	root->right = right;
	right->left = new TreeNode(2);
	Solution sol;
	vector<int> ans = sol.findMode(root);
	for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++){
		cout << *it << endl;
	}
	return 0;
}
