#include <iostream>
using namespace std;

class Solution {
private:
  inline int min(int x, int y){
    return x < y ? x : y;
  }
  inline int max(int x, int y){
    return x > y ? x : y;
  }
public:
  int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int left = max(A, E), right = max(left, min(C, G));
    int bottom = max(B, F), top = max(bottom, min(D, H));
    return (C-A) * (D-B) + (G-E) * (H-F) - (top-bottom) * (right-left);
  }
};

int main(){
  Solution sol;
  cout << (sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2)) << endl; //
  return 0;
}
