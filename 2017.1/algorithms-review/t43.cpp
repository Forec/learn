#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int sign1 = (num1[0] == '+' || num1[0] == '-') ? 44 - num1[0] : 1;
    int sign2 = (num2[0] == '+' || num2[0] == '-') ? 44 - num2[0] : 1;
    int ansSign = sign1 * sign2;
    vector<int> ans(num1.length() + num2.length()+1, 0);
    string result = "";
    int last = num1.length() + num2.length();
    for (int i = num2.length() -1; i >= (num2[0] == '+' || num2[0] == '-' ? 1 : 0); i--){
      int c = 0, base = num2[i] - '0', mul;
      int index = last - (num2.length() - 1 - i);
      for (int j = num1.length() - 1; j >= (num1[0] == '+' || num1[0] == '-' ? 1 : 0); j--){
        mul = base * (num1[j] - '0') + c + ans[index];
        c = mul / 10;
        ans[index--] = mul % 10;
      }
      while (c != 0){
        mul = ans[index] + c;
        ans[index--] = mul % 10;
        c = mul / 10;
      }
    }
    int i =0;
    while (ans[i] == 0) i++;
    for (; i <= last; i++){
      result = result + to_string(ans[i]);
    }
    if (result == "")
      result = "0";
    if (result != "0" && ansSign == -1){
      result = "-" + result;
    }
    return result;
  }
};

int main(){
  Solution sol;
  vector<bool> tests = {(sol.multiply("14213", "-12312") == "-174990456"),
                        (sol.multiply("-1", "+0") == "0"),
                        (sol.multiply("-99", "-9999") == "989901")};
  bool pass = true;
  for (int i = 0; i < tests.size(); i++){
    if (!tests[i]){
      pass=  false;
      cout << "test case " << i << " failed!" << endl;
    }
  }
  if (pass){
    cout << "all test cases passed" << endl;
  } else {
    cout << "error happended" << endl;
  }
  return 0;
}
