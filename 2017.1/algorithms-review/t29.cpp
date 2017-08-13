#include <iostream>

using namespace std;
typedef long long ll;

class Solution {
public:
int divide(int n_, int d_) {
    if(d_ == 1)
        return n_;
    if(n_ == INT_MIN && abs(d_) == 1 || d_== 0)
        return INT_MAX;
    ll ans=0;
    ll n=abs((ll)n_);
    ll d=abs((ll)d_);
    while(n>=d){
        ll a=d;
        ll m=1;
        while((a<<1) < n){a<<=1;m<<=1;}
        ans+=m;
        n-=a;
    }
    if((n_<0&&d_>=0)||(n_>=0&&d_<0))
        return -ans;
    return ans;
}
};
int main(){
	Solution sol;
	cout << sol.divide(-2147483648, -1) << endl;
	return 0;
}
