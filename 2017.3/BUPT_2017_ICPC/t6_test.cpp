#include <iostream>

using namespace std;

class mat {
public:
	long long m[2][2];
};

mat multiplyMats(mat a, mat b){
	mat res;
	for(int i = 0; i < 2; i++){
    for(int j = 0; j < 2; j++){
      res.m[i][j]=0;
      for(int k = 0; k < 2; k++)
        res.m[i][j] += a.m[i][k] * b.m[k][j] % 1000000007;
      res.m[i][j] %= 1000000007;
    }
  }
	return res;
}

mat powerMats(mat base, long long pow) {
	mat res, p = base;
  res.m[0][0] = res.m[1][1] = 1;
  res.m[0][1] = res.m[1][0] = 0;
	while(pow != 0) {
    if(pow & 1) {
      res = multiplyMats(res, p);
      pow--;
    }
    pow >>= 1;
    p = multiplyMats(p, p);
  }
	return res;
}

int main(){
	long long n;
  mat Base;
  Base.m[0][0] = 2; Base.m[0][1] = 3;
  Base.m[1][0] = 1; Base.m[1][1] = 0;
	while(cin >> n) {
    if (n == 0)
      cout << 1 << endl;
    else{
      mat ans = powerMats(Base, n-1);
      cout << (ans.m[0][0] + ans.m[0][1]) % 1000000007 << endl;
    }
  }
	return 0;
}
