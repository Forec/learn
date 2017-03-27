#include <iostream>
#include <deque>

using namespace std;

class MyStack {
private:
  deque<int> q;
public:
  MyStack() {
    q.clear();
  }
  void push(int x) {
    q.push_front(x);
  }
  int pop() {
    int value = q.front();
    q.pop_front();
    return value;
  }
  int top() {
    return q.front();
  }
  bool empty() {
    return q.empty();
  }
};

int main(){
  MyStack obj;
  obj.push(3);
  obj.push(2);
  cout << (2 == obj.pop()) << endl;
  cout << (3 == obj.top()) << endl;
  cout << (3 == obj.pop()) << endl;
  cout << (true == obj.empty()) << endl;
  return 0;
}
