#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <string>
#include "test/quickcheck.h"

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> dict;
    for (auto it = s.begin(); it != s.end(); it++){
      if (dict.count(*it) == 0)
        dict[*it] = 0;
      dict[*it] ++;
    }
    for (auto it = t.begin(); it != t.end(); it++){
      if (dict.count(*it) == 0 || dict[*it] == 0)
        return false;
      dict[*it] --;
    }
    for (auto it = dict.begin(); it != dict.end(); it++){
      if (it->second != 0)
        return false;
    }
    return true;
  }
};

int main(){
  Solution sol;
  cout << (1 == sol.isAnagram("anagram","nagaram")) << endl;
  cout << (0 == sol.isAnagram("car", "pat")) << endl;
  return 0;
}
