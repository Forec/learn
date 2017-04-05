#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    if (citations.size() == 0)
      return 0;
    sort(citations.begin(), citations.end());
    reverse(citations.begin(), citations.end());
    int h = 0;
    for (int i = 0; i < citations.size(); i++){
      if (i + 1 <= citations[i]){
        if (i < citations.size() - 1 && i + 1 >= citations[i+1])
          h = i+1;
      }
    }
    if (citations[citations.size() - 1] >= citations.size())
      return citations.size();
    return h;
  }
};

int main(){
  vector<int> citations = {3, 0, 6, 1, 5};
  Solution sol;
  cout << sol.hIndex(citations) << endl;
  return 0;
}
