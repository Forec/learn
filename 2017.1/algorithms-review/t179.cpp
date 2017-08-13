#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


// 3462 34 9 8

bool cmp_stupid(int x, int y){
  string strx = to_string(x);
  string stry = to_string(y);
  //  cout << x << " " << y << " " << strx << " "  << strx.size() << " "<<stry << " " << stry.size() << endl;
  int i = 0, j = 0;
  while (i < strx.size() && j < stry.size()){
    if (strx[i] != stry[j])
      return stry[j] < strx[i];
    i++;
    j++;
  }
  if (strx.size() == stry.size())
    return true;
  if (strx.size() < stry.size()){
    while (j < stry.size()){//} && j < 2 * strx.size()){
      if (stry[j] != stry[j-strx.size()]){
        return stry[j] < stry[j-strx.size()];
      }
      j++;
    }
    return true;
  }
  if (stry.size() < strx.size()){
    while (i < strx.size()){//} && i < 2 * stry.size()){
      if (strx[i] != strx[i - stry.size()]){
        return strx[i] > strx[i-stry.size()];
      }
      i++;
    }
    return false;
  }
}

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> arr;
    for (auto i : nums){
      arr.push_back(to_string(i));
    }
    sort(arr.begin(), arr.end(), [](string &s1, string &s2){ return s1+s2 > s2 + s1;});
    string res = "";
    for (int i = 0; i < arr.size(); i++){
      res += arr[i];
    }
    int i = 0;
    while (i < res.size() && res[i] == '0')
      i++;
    if (i == res.length())
      return "0";
    return res.substr(i);
  }
};

int main(){
  Solution sol;
  vector<int> para = {3, 30, 34, 5, 9};
  vector<int> para3 = {121, 12};
  vector<int> para2 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  cout << sol.largestNumber(para) << endl;
  return 0;
}
