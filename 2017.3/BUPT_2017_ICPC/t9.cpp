#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  int n, T;
  while (cin >> n){
    cin >> T;
    vector<int> h(n, 0);
    int minHeight = 101;
    int minHeightIndex = 0;
    for (int i = 0; i < n; i ++){
      cin >> h[i];
      if (h[i] < minHeight){
        minHeight = h[i];
        minHeightIndex = i;
      }
    }
    double rate = 1.0;
    double base = (double)minHeight;
    for (int i = 0; i < n; i++){
      if (i == minHeightIndex)
        continue;
      double hi = (double)h[i];
      double irate = hi / base;
      irate = sqrt(irate);
      rate += irate;
    }
    double ti = ((double) T) / rate;
    double g = 2 * base / (ti * ti);
    printf("%.7f\n", g);
  }
  return 0;
}
