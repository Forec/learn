#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int t, n;
  cin >> t;
  while (t--){
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++){
      cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    long long ans = 0;
    for (int i = 0; i < n; i++){
      int target = -nums[i];
      if (target < 0)
        break;
      int front = i + 1;
      int back = n - 1;
      while (front < back){
        int sum = nums[front] + nums[back];
        if (sum < target){
          front ++;
        } else if (sum > target){
          back--;
        } else {
          long long n1 = nums[i];
          long long n2 = nums[front];
          long long n3 = nums[back];
          long long mn1 = n1 * n1 % 1000000007;
          long long mn2 = n2 * n2 % 1000000007;
          long long mn3 = n3 * n3 % 1000000007;
          ans = (ans + ((mn1 + mn2 + mn3) % 1000000007)) % 1000000007;
          while (front < back && nums[front] == n2) front++;
          while (front < back && nums[back] == n3) back--;
        }
      }
      while (i + 1 < n && nums[i+1] == nums[i])
        i++;
    }
    cout << ans << endl;
  }
  return 0;
}
/*
3
6
-1 0 1 2 -1 4
6
-3 2 1 0 3 4
2
1 2
*/
