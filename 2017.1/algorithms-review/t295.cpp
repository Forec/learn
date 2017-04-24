#include <iostream>
#include <queue>
using namespace std;

class MedianFinder {
  priority_queue<long> small, large;
public:
  void addNum(int num) {
    small.push(num);
    large.push(-small.top());
    small.pop();
    if (small.size() < large.size()) {
      small.push(-large.top());
      large.pop();
    }
  }
  double findMedian() {
    return small.size() > large.size()
      ? small.top()
      : (small.top() - large.top()) / 2.0;
  }
};


int main() {
  MedianFinder med;
  med.addNum(1);
  med.addNum(3);
  cout << med.findMedian() << endl;
  med.addNum(2);
  cout << med.findMedian() << endl;
  return 0;
}
