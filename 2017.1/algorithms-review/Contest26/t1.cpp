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
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
  inline int max(int x, int y){
    return x > y? x : y;
  }
public:
  int findLUSlength(string a, string b) {
    if (a.length() != b.length())
      return max(a.length(), b.length());
    if (a == b)
      return -1;
  }
};

int main(){
  Solution sol;
  cout << sol.findLUSlength("aba", "cdc") << endl;
  cout << sol.findLUSlength("abababa", "cdcbaba") << endl;
  cout << sol.findLUSlength("aefawfawfawfaw","aefawfeawfwafwaef") << endl;
  return 0;
}
