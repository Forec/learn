#include <vector>
#include <iostream>
#include <unordered_map>
#include "test/quickcheck.h"
using namespace std;

struct Para {
  vector<int> p;
  friend ostream & operator << (ostream & os, const Para & para) {
    os << "[";
    if (para.p.size() > 0){
      cout << para.p[0];
      for (int i = 1; i < para.p.size(); i++){
        cout << ", " << para.p[i];
      }
    }
    cout << "]";
  }
};

class Solution {
private:
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++){
      if (dict.count(nums[i]) == 0)
        dict[nums[i]] = 1;
    }
    int maxm = 0;
    for (unordered_map<int, int>::iterator it = dict.begin();
         it != dict.end(); it++){
      if (it->second == 1) {
        int num = it->first - 1;
        int can = 1;
        while (dict.find(num) != dict.end() && dict[num] == 1){
          can++;
          num--;
        }
        if (dict.find(num) != dict.end()){
          can += dict[num];
        }
        for (int j = it->first; j > num; j--){
          dict[j] = can--;
        }
      }
      maxm = max(maxm, dict[it->first]);
    }
    return maxm;
  }
  int run(Para pa){
    return longestConsecutive(pa.p);
  }
};

int main(){
  vector<vector<int>> paras = {{100, 4, 200, 1, 2, 3}, {}};
  vector<Para> _ps;
  for (int i  =0; i <paras.size(); i++){
    Para tmp;
    tmp.p = paras[i];
    _ps.push_back(tmp);
  }
  vector<int> ans = {4, 0};
  QuickCheck<Para, int, Solution> *q = new QuickCheck<Para, int, Solution>(_ps, ans);
  q->runTests();
  return 0;
}
