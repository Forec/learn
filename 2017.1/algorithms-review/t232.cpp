#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> s;
  stack<int> tmp;
public:
  MyQueue() {
    while (!s.empty()) s.pop();
    while (!tmp.empty()) tmp.pop();
  }
  void push(int x) {
    s.push(x);
  }
  int pop() {
    while (!s.empty()){
      tmp.push(s.top());
      s.pop();
    }
    int res = tmp.top();
    tmp.pop();
    while (!tmp.empty()){
      s.push(tmp.top());
      tmp.pop();
    }
    return res;
  }
  int peek() {
    while (!s.empty()){
      tmp.push(s.top());
      s.pop();
    }
    int res = tmp.top();
    while (!tmp.empty()){
      s.push(tmp.top());
      tmp.pop();
    }
    return res;
  }
  bool empty() {
    return s.empty();
  }
};

int main(){
  MyQueue obj;
  obj.push(4);
  obj.push(5);
  obj.push(6);
  obj.push(7);
  int param_2 = obj.pop();
  int param_3 = obj.peek();
  bool param_4 = obj.empty();
  cout << param_2 << " " << param_3 << " " << param_4 << endl;
 return 0;
}
