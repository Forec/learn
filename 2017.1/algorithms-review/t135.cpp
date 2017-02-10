#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int candy(vector<int>& ratings) {
    vector<int> cand(ratings.size(), 1);
    for (int i = 0; i < ratings.size() - 1; i++){
      if (ratings[i+1] > ratings[i] && cand[i] >= cand[i+1]){
        cand[i+1] = cand[i] + 1;
      }
    }
    int sum = 0;
    for (int i = ratings.size() -1; i >= 1; i--){
      if (ratings[i-1] > ratings[i] && cand[i-1] <= cand[i]){
        cand[i-1] = cand[i] + 1;
      }
      sum += cand[i];
    }
    return sum + cand[0];
  }
};

int main(){
  Solution sol;
  vector<int> rating = {1, 2, 3, 4, 5};
  int ans1 = sol.candy(rating);
  cout << ans1 << endl; // 0 1
  return 0;
}
