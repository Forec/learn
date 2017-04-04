#include <iostream>

using namespace std;

int rule[26][26];

void clear(){
  for (int i = 0; i < 26; i++){
    for (int j = 0; j < 26; j++){
      rule[i][j] = -1;
    }
  }
}

inline int min(int x, int y){
  if (x == -1)
    return y;
  return x < y ? x : y;
}

int main(){
  int t, m, weight;
  char from, to;
  string a, b;
  cin >> t;
  while (t --){
    clear();
    cin >> a;
    cin >> b;
    cin >> m;
    for (int i = 0; i < m; i++){
      cin >> from >> to >> weight;
      rule[from - 'a'][to - 'a'] = min(rule[from - 'a'][to - 'a'], weight);
    }
    if (a.length() != b.length())
      cout << -1 << endl;
    else{
      int res = 0;
      int n = a.length();
      for (int i = 0; i < n; i++){
        if (a[i] == b[i])
          continue;
        int mincost = -1;
        if (rule[b[i]-'a'][a[i]-'a'] != -1)
          mincost = rule[b[i]-'a'][a[i] -'a'];
        for (int j = 0; j < 26; j++){
          if (rule[a[i] - 'a'][j] != -1 && ((rule[b[i] - 'a'][j] != -1) || (b[i] - 'a' == j))){
            if (b[i] - 'a' == j)
              mincost = min(mincost, rule[a[i] -'a'][j]);
            else
              mincost = min(mincost, rule[a[i]-'a'][j] + rule[b[i] - 'a'][j]);
          }
        }
        if (mincost != -1)
          res += mincost;
        else{
          res = -1;
          cout << -1 << endl;
          break;
        }
      }
      if (res != -1)
        cout << res << endl;
    }
  }
  return 0;
}
