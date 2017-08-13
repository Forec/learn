#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>
#include "test/quickcheck.h"

using namespace std;

class Solution {
private:
  vector<int> splitVersion(string version){
    int i = 0, j = 0;
    vector<string> numbers;
    while (i < version.length()){
      for (j = i; j < version.length() && version[j] != '.'; j++);
      int gap = j - i;
      if (gap != 0){
        numbers.push_back(version.substr(i, gap));
      }
      i = j+1;
    }
    vector<int> integers;
    for (i = 0; i < numbers.size(); i++){
      j = 0;
      while (j < numbers[i].length() && numbers[i][j] == ' ')
        j ++;
      if (j == numbers[i].length())
        continue;
      int startIndex = j;
      j = numbers[i].length() -1;
      while (j >= startIndex && numbers[i][j] == ' ') j--;
      stringstream ss;
      int tmp;
      ss << numbers[i].substr(startIndex, j - startIndex+1);
      ss >> tmp;
      integers.push_back(tmp);
    }
    return integers;
  }
public:
  int compareVersion(string version1, string version2) {
    vector<int> v1 = splitVersion(version1);
    vector<int> v2 = splitVersion(version2);
    int v1Size = v1.size(), v2Size = v2.size();
    while (v1Size > 0 && v1[v1Size-1] == 0) v1Size--;
    while (v2Size > 0 && v2[v2Size-1] == 0) v2Size--;
    int minSize = v1Size < v2Size ? v1Size: v2Size;
    for (int i = 0; i < minSize; i++){
      if (v1[i] < v2[i])
        return -1;
      else if (v1[i] > v2[i])
        return 1;
    }
    if (v1Size > v2Size)
      return 1;
    if (v1Size < v2Size)
      return -1;
    return 0;
  }
  int run(PAIR<string, string> para){
    return compareVersion(para.first, para.second);
  }
};

int main(){
  vector<PAIR<string, string>> paras = {PAIR<string, string>("0.1", "1.1"),
                                        PAIR<string, string>("1.1", "1.2"),
                                        PAIR<string, string>("13.37", "1.2"),
                                        PAIR<string, string>("1.3.4.5", "1.3.4.5"),
                                        PAIR<string, string>("1.0", "1")};
  vector<int> ans = {-1, -1, 1, 0, 0};
  QuickCheck<PAIR<string, string>, int, Solution> q(paras, ans);
  q.runTests();
  return 0;
}
