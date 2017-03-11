#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int i = 0, j = numbers.size()-1;
    vector<int> ans;
    while (i < j){
      if (numbers[i] + numbers[j] == target){
        ans.push_back(i+1);
        ans.push_back(j+1);
        return ans;
      }
      if (numbers[i] + numbers[j] < target){
        i++;
      } else {
        j--;
      }
    }
    return ans;
  }
};


int main(){
  Solution sol;
  vector<int> numbers= {2, 7, 11, 15};
  vector<int> ans = sol.twoSum(numbers, 9);
  cout << ans[0] << " " << ans[1] << endl;
  return 0;
}
