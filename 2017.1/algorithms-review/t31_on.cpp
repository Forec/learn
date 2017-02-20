#include <iostream>
#include <vector>
using namespace std;

class Solution{
private:
  void swap(int &i, int &j){
    int tmp = i;
    i = j;
    j = tmp;
  }
  void reverseSort(vector<int> & num, int start, int end){
    if (start > end) return;
    for (int i = start; i <= (end + start) / 2; i++)
      swap(num[i], num[start + end - i]);
  }
public:
  void nextPermutation(vector<int> & num){
    int n = num.size();
    if (n < 2)
      return;
    int index = n - 1;
    while (index > 0){
      if (num[index-1] < num[index])
        break;
      index--;
    }
    if (index == 0){
      reverseSort(num, 0, n-1);
    }
    else {
      int val = num[index-1];
      int j = n - 1;
      while (j >= index){
        if (num[j] > val)
          break;
        j--;
      }
      swap(num[j], num[index-1]);
      reverseSort(num, index, n -1);
    }
  }
};

int main(){
  vector<int> para = {2,3, 1};
  Solution sol;
  sol.nextPermutation(para);
  for (vector<int>::iterator it = para.begin(); it != para.end(); it++){
    cout << *it<< " " ;
  }
  cout << endl;
  return 0;
}
