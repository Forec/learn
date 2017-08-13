#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "test/quickcheck.h"

using namespace std;

template <typename T>
class VECTOR {
private:
  vector<T> vec;
public:
  VECTOR(vector<T>& v){
    vec = v;
  }
  friend  ostream & operator << (ostream & os, const VECTOR &v){
    os << "[";
    if (v.vec.size() > 0){
      cout << v.vec[0];
      for (int i = 1; i < v.vec.size(); i++){
        os << ", " << v.vec[i];
      }
    }
    os << "]";
    return os;
  }
  vector<T> getVEC(){
    return vec;
  }
};

class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++){
      string numOrOp = tokens[i];
      if (numOrOp == "+" || numOrOp == "-" || numOrOp == "*" || numOrOp == "/"){
        int op1, op2;
        op2 = s.top();
        s.pop();
        op1 = s.top();
        s.pop();
        int ans;
        if (numOrOp == "+"){
          ans = op1 + op2;
        } else if (numOrOp == "-"){
          ans = op1 - op2;
        } else if (numOrOp == "*"){
          ans = op1 * op2;
        } else{
          ans = op1 / op2;
        }
        s.push(ans);
      } else {
        s.push(atoi(numOrOp.c_str()));
      }
    }
    return s.top();
  }
  int run(VECTOR<string> &v){
    vector<string> para = v.getVEC();
    return evalRPN(para);
  }
};

int main (){
  vector<vector<string>> basics = {{"2", "1", "+", "3", "*"},
                                   {"4", "13", "5", "/", "+"}};
  vector<VECTOR<string>> inputs;
  for (int i = 0; i < basics.size(); i++){
    inputs.push_back(VECTOR<string>(basics[i]));
  }
  vector<int> ans = {9, 6};
  QuickCheck<VECTOR<string>, int, Solution> q(inputs, ans);
  q.runTests();
  return 0;
}
