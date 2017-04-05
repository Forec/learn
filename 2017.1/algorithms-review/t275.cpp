#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int hIndex(vector<int>& citations) {
    int left = 0, len = citations.size(), right = len - 1, mid;
    while (left <= right){
      mid = left + (right - left) / 2;
      if (citations[mid] >= len-mid)
        right = mid - 1;
      else
        left = mid + 1;
    }
    return len - left;
  }
};

int main (){
  vector<int> para = {1, 3, 5, 6, 6};
  Solution sol;
  cout << sol.hIndex(para) << endl;
  return 0;
}
