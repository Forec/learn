#include <iostream>

using namespace std;

class MinStack {
private:
  int * dat;
  int _top;
  int size;
  int minm = -1;
public:
  MinStack() {
    _top = 0;
    size = 128;
    dat = new int[size];
  }
  void push(int x) {
    if (_top >= size){
      int * tmp = dat;
      size *= 2;
      dat = new int[size];
      for (int i = 0; i < _top; i++){
        dat[i] = tmp[i];
      }
      delete[] tmp;
    }
    if (_top == 0 || x < minm)
      minm = x;
    dat[_top++] = x;
  }
  void pop() {
    if (_top > 0)
      _top--;
    if (dat[_top] == minm && _top > 0){
      minm = dat[0];
      for (int i = 1; i < _top; i++)
        minm = minm <= dat[i] ? minm : dat[i];
    }
  }
  int top() {
    if (_top <= 0)
      return 0;
    return dat[_top-1];
  }
  int getMin() {
    if (_top <= 0)
      return 0;
    return minm;
  }
};

int main(){
  MinStack minStack;
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;
  minStack.pop();
  cout << minStack.top() << endl;
  cout << minStack.getMin() << endl;
  return 0;
}
