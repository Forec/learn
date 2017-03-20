#include <iostream>
#include <vector>
#include <memory.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <sstream>
#include <cstdio>

using namespace std;

const int maxn = 106;
const int inf = 1e8;
int dp[maxn][maxn][maxn];

class Solution {
private:
  string s;

  int solve(int l,int r,int d){
    if(l>r)return 0;
    if(s[l]-'A'==d&&l==r)return dp[l][r][d]=0;
    if(l==r)return dp[l][r][d]=1;
    if(dp[l][r][d]!=-1)return dp[l][r][d];
    dp[l][r][d]=inf;
    for(int i=0;i<26;i++){
      dp[l][r][d]=min(dp[l][r][d],solve(l,r,i)+1);
    }
    if(s[l]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l+1,r,d));
    if(s[r]-'A'==d)dp[l][r][d]=min(dp[l][r][d],solve(l,r-1,d));
    for(int i=l+1;i<r;i++){
      if(s[i]-'A'==d){
        dp[l][r][d]=min(dp[l][r][d],solve(l,i-1,d)+solve(i+1,r,d));
      }
    }
    return dp[l][r][d];
  }
  int fuck(){
    if (!s.length())
      return 0;
    int n = s.length();
    string p(n, s[0]);
    int count = 1;
    while (s[n-1] == s[0])
      n--;

    // for (int i = 0; i < s.length(); i++)
    //   printf("%3d", i);
    // cout << endl;

    for (int i = 0; i < n; i++){
      if (s[i] == p[i])
        continue;
      char code = s[i];
      count++;
      //////////////////////////////////////
      // for (int st = 0;  st < s.length(); st++)
      //   cout << "  " << p[st] ;
      // cout << "  " << i <<endl;
      ///////////////////////////////////////
      while (i < n && s[i] == code)
        i++;

      int j = n-1;
      while (s[j] != code)
        j--;

      int code_end = j;
      int cover_segments = 0, tocover_segment = 0;

      j = i;
      while (j <= code_end) {
        if (s[j] == p[j]){
          cover_segments++;
          while (j < n && s[j] == p[j])
            j++;
        }
        else if (s[j] == code){
          tocover_segment ++;
          while (j < n && s[j] == code)
            j++;
        } else
          j++;
      }

      if (cover_segments < tocover_segment){
        for (int k = i; k <= code_end; k++)
          p[k] = code;
        while (s[n-1] == code)
          n--;
      }
      i--;
    }
    return count;
  }
public:
  void fuck(int size){
    srand(time(NULL));
    for (int i = 0; i < size; i++){
      int length = rand() % 50 + 1;
      stringstream ss;
      for (int j = 0; j < length; j++){
        char code = 'A' + (rand() % 26);
        ss << code;
      }
      s = ss.str();
      memset(dp, -1, sizeof(dp));
      int ans1 = fuck();
      int ans2 = solve(0, s.length()-1, 27);
      if (ans1 != ans2){
        cout << "ERROR: length = " << length << ", s = \"" << s << "\", ans1 = " << ans1 << ", ans2 = " << ans2 << endl; 
      }
    }
  }
};

int main(){
  string a = "ABCBA";
  string b = "AAAAA";
  string c = "AAABBCDDAADDCCCBCACACAAA"; // 8
  Solution sol;
  sol.fuck(20);
  return 0;
}
