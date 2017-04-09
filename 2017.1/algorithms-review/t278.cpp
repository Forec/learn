#include <iostream>
using namespace std;

bool isBadVersion(int version){
  if (version>=1)
    return true;
  return false;
};

class Solution {
public:
  int firstBadVersion(int n) {
    int left = 1, right = n;
    while (left < right - 1){
      int mid = left + (right - left) / 2;
      if (isBadVersion(mid)){
        right = mid;
      } else {
        left = mid;
      }
    }
    if (isBadVersion(left))
      return left;
    return right;
  }
};


int main(){
  Solution sol;
  cout << sol.firstBadVersion(1) << endl;
  return 0;
}
