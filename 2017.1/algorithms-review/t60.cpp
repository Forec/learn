#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  vector<int> plusOne(vector<int> & digits){
    vector<int> ans(digits.size(), 0);
    int c = 1, temp;
    for (int i = digits.size() - 1; i >= 0; i--){
      temp = digits[i] + c;
      c = temp / 10;
      temp %= 10;
      ans[i] = temp;
    }
    if (c == 1)
      ans.insert(ans.begin(), 1);
    return ans;
  }
};

int main(){
  Solution sol;
  vector<int> para1 = {1, 2, 3, 9};
  vector<int> para2 = {9, 9, 9, 9};
  vector<int> para3 = {1, 2, 3, 4, 5};
  vector<int> ans1 = sol.plusOne(para1);
  vector<int> ans2 = sol.plusOne(para2);
  vector<int> ans3 = sol.plusOne(para3);
  for (int i = 0; i < ans1.size(); i++)
    cout << ans1[i] << " ";
  cout << endl;
  for (int i = 0; i < ans2.size(); i++)
    cout << ans2[i] << " ";
  cout << endl;
  for (int i = 0; i < ans3.size(); i++)
    cout << ans3[i] << " ";
  cout << endl;
  return 0;
}
