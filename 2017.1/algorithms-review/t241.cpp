#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
private:
  vector<string> parsed;
  vector<vector<vector<int>>> dict;
  vector<string> parseInput(string input){
    vector<string> res;
    int pre = 0, i;
    for (i = 0; i < input.length(); i++){
      if (pre == i && (input[i] == '-' || input[i] == '+'))
        continue;
      if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
        res.push_back(input.substr(pre, i-pre));
        res.push_back(input.substr(i, 1));
        pre = i + 1;
      }
    }
    if (i > pre){
      res.push_back(input.substr(pre, i-pre));
    }
    return res;
  }
public:
  Solution () {
    parsed.clear();
    dict.clear();
  }
  vector<int> diffWaysToCompute(string input) {
    parsed = parseInput(input); // must odd
    if (parsed.size() == 0)
      return vector<int>();
    int numbers = parsed.size() / 2 + 1;
    int operators = parsed.size() / 2;
    dict.resize(numbers, vector<vector<int>>(numbers, vector<int>()));
    for (int i = 0; i < numbers; i++){
      int value = atoi(parsed[i * 2].c_str());
      vector<int> tmp = {value};
      dict[i][i] = tmp;
    }
    for (int len = 1; len < numbers; len++){
      for (int i = 0; i + len < numbers; i++) {
        int j = i + len;
        vector<int> res = {};
        for (int k = i+1; k <= j; k++){
          vector<int> left = dict[i][k-1];
          vector<int> right = dict[k][j];
          for (auto p = left.begin(); p != left.end(); p++){
            for (auto q = right.begin(); q != right.end(); q++){
              string op = parsed[2 * k - 1];
              if (op == "+")
                res.push_back((*p) + (*q));
              else if (op == "-")
                res.push_back((*p) - (*q));
              else if (op == "*")
                res.push_back((*p) * (*q));
            }
          }
        }
        dict[i][j] = res;
      }
    }
    return dict[0][numbers-1];
  }
};

int main(){
  string input = "";
  Solution sol;
  vector<int> ans = sol.diffWaysToCompute(input);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " " ;
  }
  return 0;
}
