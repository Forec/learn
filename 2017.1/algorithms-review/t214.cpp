#include <iostream>
#include <vector>
#include <algorithm>
#include "test/quickcheck.h"

using namespace std;

class Solution_fuck {
public:
  string shortestPalindrome(string s) {
    if (s.length() == 0 || s.length() == 1)
      return s;
    int mid = (s.length()-1) >> 1, left, right;
    bool even = ((s.length() & 1) == 0);
    bool origin = even;
    do {
      if (!even)
        left = mid - 1;
      else
        left = mid;
      right = mid + 1;
      cout << mid << " " << left << " " << right << endl;
      while (left >= 0 && s[left] == s[right]){
        left--;
        right++;
      }
      if (origin != even)
        mid--;
      even = !even;
    } while (left >= 0 && mid >= 0);
    string addAtFront = s.substr(right);
    reverse(addAtFront.begin(), addAtFront.end());
    return addAtFront + s;
  }
  string run(string s){
    return shortestPalindrome(s);
  }
};

class Solution {
public:
  string shortestPalindrome(string s) {
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string l = s + "#" + rev_s;
    vector<int> p(l.size(), 0);
    for (int i = 1; i < l.size(); i++) {
      int j = p[i - 1];
      while (j > 0 && l[i] != l[j])
        j = p[j - 1];
      p[i] = (j += l[i] == l[j]);
    }
    return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
  }
  string run(string s){
    return shortestPalindrome(s);
  }
};

int main(){
  vector<string> inputs = {"abcd", "aacecaaa", "", "abbacd", "a", "aba", "aabba"};
  vector<string> outputs = {"dcbabcd", "aaacecaaa", "", "dcabbacd", "a", "aba", "abbaabba"};
  QuickCheck<string, string, Solution> q(inputs, outputs);
  q.runTests();
  return 0;
}
