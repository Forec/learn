#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include "../test/quickcheck.h"

using namespace std;

class Solution {
public:
  bool subseq(string &x, string &y) {
    int i = 0, j = 0;
    for(i=0;i<(int)x.size();i++) {
      if(j<(int)y.size() && x[i]==y[j]) ++j;
    }
    return j==(int)y.size();
  }
  int findLUSlength(vector<string>& strs) {
    int n = strs.size();
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(strs[i].size() > strs[j].size()) swap(strs[i], strs[j]);
    for(int i=n-1;i>=0;i--) {
      bool ok = true;
      for(int j=0;j<n;j++)
        if(j!=i && subseq(strs[j], strs[i]))
          ok = false;
      if(ok) {
        return strs[i].size();
      }
    }
    return -1;
  }
};

int main(){
  Solution sol;
  return 0;
}
