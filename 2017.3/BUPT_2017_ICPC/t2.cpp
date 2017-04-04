#include <iostream>
#include <map>

using namespace std;

const int base = 1000000007;

int power(long long b, int pas){
  if (b == 1)
    return 1;
  int p = pas;
  long long res = 1;
  while (p != 0){
    if (p & 1){
      res *= b;
      if (res >= base)
        res %= base;
      p--;
    }
    p >>= 1;
    b = b * b;
    if (b >= base)
      b %= base;
  }
  return res;
}

int C(int n, int k){
  long long up = 1, down = 1;
  int fac_up = k+1, fac_down = 2;
  while (fac_up <= n) {
    up *= fac_up++;
    if (up >= base)
      up %= base;
  }
  while (fac_down <= n-k){
    down *= fac_down++;
    if (down >= base)
      down %= base;
  }
  int b_p_2 = power(down, base - 2);
  long long res = (up * b_p_2) % base;
  return res;
}

int main(){
  int n;
  long long ans, ck, left;
  while (cin >> n){
    if (n == 1)
      cout << 1 << endl;
    else{
      ans = 0;
      map<int, int> dict;
      for (int i = 1; i < n; i++){
        if (dict.count(i) == 1 || dict.count(n-i) == 1){
          if (dict.count(i) == 1)
            ck = dict[i];
          else
            ck = dict[n-i];
        }
        else{
          ck = C(n, i);
          dict[i] = ck;
        }
        left = power(i, n-i);
        ck *= left;
        ck %= base;
        ans += ck;
      }
    }
    cout << ans%base << endl;
  }
  return 0;
}
