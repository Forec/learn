#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ans;
    int index = 0;
    vector<string> currentLine;
    int currentLineLength = 0;
    while (index < words.size()){
      currentLine.clear();
      currentLineLength = 0;
      while (index < words.size() &&
             ((currentLineLength ==0 && words[index].length() <= maxWidth)
              ||
              (currentLineLength > 0 && 1 + currentLineLength + words[index].length() <= maxWidth)
              )){
        currentLine.push_back(words[index]);
        if (currentLineLength == 0)
          currentLineLength = words[index].length();
        else
          currentLineLength += (1 + words[index].length());
        index++;
      }
      vector<int> intervals(currentLine.size()-1, 1);
      if (index == words.size()){
        stringstream build;
        for (int i = 0; i < currentLine.size()-1; i++){
          build << currentLine[i] << " ";
        }
        build << currentLine[currentLine.size()-1];
        for (int i = 0; i < maxWidth - currentLineLength; i++)
          build << " " ;
        ans.push_back(build.str());
        return ans;
      }
      while (currentLineLength < maxWidth){
        int left = min(maxWidth - currentLineLength, currentLine.size()-1);
        for (int i = 0; i < left; i++)
          intervals[i] ++;
        currentLineLength += left;
        if (left == 0)
          break;
      }
      stringstream build;
      intervals.push_back(maxWidth - currentLineLength);
      for (int i = 0; i < currentLine.size(); i++){
        build << currentLine[i];
        for (int j = 0; j < intervals[i]; j++)
          build << " ";
      }
      ans.push_back(build.str());
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector<string> para = {"This", "is", "an", "example", "of", "text", "justification."};
  vector<string> para3 = {"What","must","be","shall","be."};
  vector<string> para2 = {""};
  vector<string> ans = sol.fullJustify(para3, 12);
  for (vector<string>::iterator it = ans.begin() ; it != ans.end(); it++){
    cout << *it << endl;
  }
  return 0;
}
