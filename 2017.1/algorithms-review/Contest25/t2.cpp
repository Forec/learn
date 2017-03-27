#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
  vector<int> split(string s){
    int i = 0;
    while (i < s.length() && s[i] != '+'){
      i++;
    }
    int a, b;
    stringstream ssa;
    ssa << s.substr(0, i);
    ssa >> a;
    stringstream ssb;
    ssb << s.substr(i+1, s.length() - i - 2);
    ssb >> b;
    vector<int> res = {a, b};
    return res;
  }
public:
  string complexNumberMultiply(string a, string b) {
    vector<int> axy = split(a);
    vector<int> bxy = split(b);
    int x = axy[0], y = axy[1];
    int m = bxy[0], n = bxy[1];
    int resa = m * x - n * y, resb = n * x + m * y;
    string ans = to_string(resa) + "+" + to_string(resb) + "i";
    return ans;
  }
};

int main(){
  Solution sol;
  cout << ("0+2i" == sol.complexNumberMultiply("1+1i", "1+1i")) << endl;
  cout << ("0+-2i" == sol.complexNumberMultiply("1+-1i", "1+-1i")) << endl;
  cout << (sol.complexNumberMultiply("5+4i", "0+-2i") == "8+-10i")<< endl;
  cout << (sol.complexNumberMultiply("-2+-6i", "2+-4i") == "-28+-4i") << endl;
  return 0;
}
