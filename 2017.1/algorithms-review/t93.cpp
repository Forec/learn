#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
  string source;
  int length;
  void add(string &build, int current){
    if (build.length() == 0){
      build = to_string(current);
    } else {
      build += ("." + to_string(current));
    }
  }
  void _dfs(vector<string> & ans, int left, int index, string build, int current){
    if (left == 0 && index == length){
      ans.push_back(build);
      return;
    }
    int unused = length - index;
    if (unused < left || unused > 3 * left){
      return;
    }
    char code = source[index];
    if (current == -1){
      current = code - '0';
      if (current != 0){
        _dfs(ans, left, index+1, build, current);
      }
      add(build, current);
      _dfs(ans, left-1, index+1, build, -1);
    } else if (current / 100 > 0) {
      add(build, current);
      _dfs(ans, left - 1, index+1, build, -1);
    } else if (current < 10){
      current *= 10;
      current += code - '0';
      _dfs(ans, left, index+1, build, current);
      add(build, current);
      _dfs(ans, left-1, index+1, build, -1); // 25 
    } else if (current / 10 <= 1 || current / 10 == 2 && current % 10 <= 5){
      if (current / 10 == 2 && current % 10 == 5 && code - '0' > 5){
        //        add(build, )
        //        _dfs(ans, left-1, index, build, )
        return;
      } else {
        current *= 10;
        current += code - '0';
        add(build, current);
        _dfs(ans, left-1, index+1, build, -1);
      }
    } else {
    }
  }
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    source = s;
    length = s.length();
    _dfs(res, 4, 0, "", -1);
    return res;
  }
};

class Verify{
public:
  static Verify * getInstance(){
    if (Verify::instance == NULL){
      Verify::instance = new Verify();
      Verify::count = 0;
    }
    return Verify::instance;
  }
  void verify(vector<string> & ans, vector<string> &standard){
    printTime();
    if (ans.size() != standard.size()){
      cout << "Size not match, expected: " << standard.size() << ", got: " << ans.size() << endl;
      for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
      }
    } else {
      vector<bool> used(ans.size(), false);
      int failed = 0;
      for (int i = 0; i < standard.size(); i++){
        bool find = false;
        for (int j = 0; j < ans.size(); j++){
          if (used[j])
            continue;
          if (ans[j] == standard[i]){
            find = true;
            used[j] = true;
          }
        }
        if (!find){
          cout << "Expected \"" << standard[i] << "\" not found in ans" << endl;
          failed ++;
        }
      }
      if (failed == 0){
        cout << "Passed all " << standard.size() << " tests" << endl;
      } else {
        cout << "Passed " << standard.size() - failed << " tests, " << failed << " expected ans not found!" << endl;
      }
    }
  }
private:
  static int count;
  static Verify * instance;
  static void printTime(){
    count++;
    cout << "Test " << count << " case:" << endl;
  }
protected:
  Verify(){
  };
};

int Verify::count = 0;
Verify * Verify::instance = NULL;

int main(){
  Solution sol;
  vector<string> ans = sol.restoreIpAddresses("25525511135");
  vector<string> standard = {"255.255.11.135", "255.255.111.35"};
  vector<string> ans2 = sol.restoreIpAddresses("172162541");
  vector<string> standard2 = {"17.216.25.41","17.216.254.1","172.16.25.41","172.16.254.1","172.162.5.41","172.162.54.1"};
  Verify * v = Verify::getInstance();
  v->verify(ans, standard);
  v->verify(ans2, standard2);
  return 0;
}
