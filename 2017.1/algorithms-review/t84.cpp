#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
  int largestRectangleArea(vector<int> & height){
    stack<int> s;
    height.push_back(0);
    int sum = 0, i = 0;
    while ( i < height.size()){
      if (s.empty() || height[i] > height[s.top()]){
        s.push(i++);
      } else {
        int t = s.top();
        s.pop();
        sum = max(sum, height[t] * (s.empty() ? i : i - s.top() - 1));
      }
    }
    return sum;
  }
};

int main(){
  Solution sol;
  vector<int> para = {2, 1, 5, 6, 2, 3};
  cout << sol.largestRectangleArea(para) << endl;
  return 0;
}
