#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	int fourSumCount(vector<int> & A, vector<int>&B, vector<int> &C, vector<int> &D){
		map<int, int> dict;
		for (int i = 0 ; i < A.size(); i++){
			for (int j = 0 ; j < B.size(); j ++){
				if (dict.count(A[i]+ B[j]) > 0){
					dict[A[i]+B[j]] += 1;
				} else {
					dict[A[i]+B[j]] = 1;
				}
			}
		}
		int res = 0;
		for (int i = 0; i < C.size(); i++){
			for (int j = 0; j < D.size(); j++){
				if (dict.count(-(C[i] + D[j])) > 0)
					res += dict[-(C[i] + D[j])];
					
			}
		}
		return res;
	}
};

int main(){
	vector<int> A = {-1, -1};
	vector<int> B = {-1, 1};
	vector<int> C = {-1, 1};
	vector<int> D = {1, -1};
	Solution sol;
	cout << sol.fourSumCount(A, B, C, D) << endl;
	return 0;
}
