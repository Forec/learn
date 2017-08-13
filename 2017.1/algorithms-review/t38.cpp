#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
  string countAndSay(int n){
    if (n == 0)
      return "";
    string base = "1";
    while (--n){
      string cur = "";
      for (int i = 0; i < base.length(); i++){
        int count = 1;
        while ((i + 1 < base.length()) && (base[i] == base[i+1])){
          count ++;
          i++;
        }
        cur += to_string(count) + base[i];
      }
      base = cur;
    }
    return base;
  }
};

int main(){
  Solution sol;
  int n;
  while (1){
    cin >> n;
    cout << sol.countAndSay(n) << endl;
  }
  return 0;
}
