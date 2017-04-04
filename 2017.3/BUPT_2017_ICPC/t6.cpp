#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <utility>

using namespace std;

long long calc(long long n){
  if (n <= 1)
    return 1;
  long long fi_2 = 1, fi_1 = 1, fi;
  vector<long long>res = {1, 1};
  for (long long i = 2; i <= n; i++){
    fi = 2 * fi_1 + 3 * fi_2;
    if (fi >= 1000000007){
      fi = fi % 1000000007;
    }
    cout << "i = " << i << ", fi = " << fi << endl ;
    for (int j = 0; j < res.size() - 1;j ++){
      if (res[j] == fi_1 && res[j+1] == fi){
        cout << "j = " << j << ", i = "<< i << endl;
        return i;
      }
    }
    res.push_back(fi);
    fi_2 = fi_1;
    fi_1 = fi;
  }
  return fi;
}

int main(){
  long long n;
  cin >> n;
  calc(n);
  //  cout << calc(n) << endl;
  return 0;
}
