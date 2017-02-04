#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int j = m - 1, k = n - 1;
    for (int i = m + n - 1; i >= 0; i--) {
      if (j >= 0 && k >= 0) {
        if (nums2[k] > nums1[j])
          nums1[i] = nums2[k--];
        else
          nums1[i] = nums1[j--];
      } else if (j >= 0)
        nums1[i] = nums1[j--];
      else if (k >= 0)
        nums1[i] = nums2[k--];
    }
  }
};

int main(){
  Solution sol;
  vector<int> nums1 = {1, 1, 2, 3, 4, 7, 8, 0, 0, 0, 0, 0, 0};
  vector<int> nums2 = {3, 4, 4, 5, 7, 8};
  sol.merge(nums1, 7, nums2, 6);
  for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
    cout << *it << " ";
  cout << endl;
  return 0;
}
