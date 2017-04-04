#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int nthUglyNumber(int n) {
    if (n == 1)
      return 1;
    queue<int> mul2, mul3, mul5;
    mul2.push(2); mul3.push(3); mul5.push(5);
    int m2, m3, m5;
    while (--n){
      m2 = mul2.front();
      m3 = mul3.front();
      m5 = mul5.front();
      if (m2 < m3 && m2 < m5){
        mul2.pop();
      } else if (m3 < m2 && m3 < m5){
        mul3.pop();
        m2 = m3;
      } else if (m5 < m3 && m5 < m2){
        mul5.pop();
        m2 = m5;
      } else if (m2 == m3 && m3 == m5){
        mul2.pop();
        mul3.pop();
        mul5.pop();
      } else if (m2 == m3 && m2 < m5){
        mul2.pop();
        mul3.pop();
      } else if (m3 == m5 && m3 < m2){
        mul3.pop();
        mul5.pop();
        m2 = m3;
      } else if (m2 == m5 && m2 < m3){
        mul2.pop();
        mul5.pop();
      }
      mul2.push(m2 * 2);
      mul3.push(m2 * 3);
      mul5.push(m2 * 5);
    }
    return m2;
  }
};

int main(){
  Solution sol;
  cout << sol.nthUglyNumber(10) << endl;
  cout << sol.nthUglyNumber(100) << endl;
  return 0;
}
