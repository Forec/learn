#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
private:
  void dfs(std::vector<string> &res, string& num, int target, string cur, int pos, long cv, long pv, char op){
    if (pos == num.size() && cv == target)
      res.push_back(cur);
    else {
      for (int i = pos + 1; i <= num.size(); i++){
        string t = num.substr(pos, i-pos);
        long now = atoi(t.c_str());
        if (to_string(now).size() != t.size())
          continue;
        dfs(res, num, target, cur+'+'+t, i, cv+now, now, '+');
        dfs(res, num, target, cur+'-'+t, i, cv-now, now, '-');
        if (op == '-'){
          dfs(res, num, target, cur+'*'+t, i, cv+pv-pv*now, pv*now, op);
        } else if (op == '+'){
          dfs(res, num, target, cur+'*'+t, i, cv-pv+pv*now, pv*now, op);
        } else {
          dfs(res, num, target, cur+'*'+t, i, pv*now, pv*now, op);
        }
      }
    }
  }
public:
  vector<string> addOperators(string num, int target) {
    vector<string> res;
    if (num.empty())
      return res;
    int gen = atoi(num.c_str());
    if (gen == target && to_string(gen).size() == num.size())
      res.push_back(num);
    for (int i = 1; i < num.size(); i++){
      string s = num.substr(0, i);
      long cur = atoi(s.c_str());
      if (to_string(cur).size() != s.size())
        continue;
      dfs(res, num, target, s, i, cur, cur, '#');
    }
    return res;
  }
};

class Solution1 {
private:
  unordered_map<int, vector<string>> dfs(string left){
    unordered_map<int, vector<string>> res;
    if (left == "")
      return res;
    int total = atoi(left.c_str());
    if (to_string(total).length() == left.length()){
      res[total] = vector<string>();
      res[total].push_back(left);
    }
    for (int i = 1; i < left.size(); i++){
      string used = left.substr(0, i);
      int n1 = atoi(used.c_str());
      if (to_string(n1).length() != i)
        continue;
      unordered_map<int, vector<string>> canbe = dfs(left.substr(i));
      for (auto it = canbe.begin(); it != canbe.end(); it++){
        int right = it->first;
        vector<string> methods = it->second;
        int plus = n1 + right;
        if (res.find(plus) == res.end())
          res[plus] = vector<string>();
        for (int j = 0; j < methods.size(); j++){
          res[plus].push_back("(" + used + "+" + methods[j] + ")");
        }
        int sub = n1 - right;
        if (res.find(sub) == res.end())
          res[sub] = vector<string>();
        for (int j = 0; j < methods.size(); j++){
          res[sub].push_back("(" + used + "-" + methods[j] + ")");
        }
        int mul = n1 * right;
        if (res.find(mul) == res.end())
          res[mul] = vector<string>();
        for (int j = 0; j < methods.size(); j++){
          res[mul].push_back("(" + used + "*" + methods[j] + ")");
        }
      }
    }
    return res;
  }
public:
  vector<string> addOperators(string num, int target) {
    unordered_map<int, vector<string>> res = dfs(num);
    if (res.find(target) == res.end())
      return vector<string>();
    return res[target];
  }
};

void print(vector<string> &as){
  for (string a:as)
    cout << a << ", ";
  cout << endl;
}

int main(){
  Solution sol;
  vector<vector<string>> as;
  as.push_back(sol.addOperators("123", 6));
  as.push_back(sol.addOperators("232", 8));
  as.push_back(sol.addOperators("105", 5));
  as.push_back(sol.addOperators("00", 0));
  as.push_back(sol.addOperators("3456237490", 9191));
  for (vector<string> a : as)
    print(a);
  return 0;
}
