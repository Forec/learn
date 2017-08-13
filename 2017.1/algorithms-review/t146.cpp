#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include "test/quickcheck.h"

using namespace std;

// 表 dict：存储 key -> value 和 age 的映射关系
// 表 history: 存储 age -> key 的映射关系
// 类中存在 curTimep: 代表最新使用值的时间点
// 类中存在 repTimep: 代表下一次要置换时使用的时间点
// 插入一个值: 若未满，则直接插入，在dict 中存储 key -> <value, curTimep> 的映射，在 history 中存储 curTimep -> key 的关系。最后 curTimep ++
//            若已满，则置换。取出 replace = history[repTimep]，repTimep ++，并将 dict[replace] 置换为新值。
// 获取一个值：若 dict 中存在该 key 则取出，否则返回 -1
//           若存在，同时更新 history，将 history[原本的 timep] 删除，增加 history[curTimep]，并更新其timestemp 为 curTimep++


class LRUCache {
private:
  unordered_map<int, pair<int, int>> dict;
  unordered_map<int, int> history;
  int cap;
  int currentTimepoint;
  int toReplaceTimepoint;
  void updateHistory(int key, pair<int, int> & p){
    if (history.count(p.second) > 0)
      history.erase(p.second);
    history[currentTimepoint] = key;
    p.second = currentTimepoint++;
  }
public:
  LRUCache(int capacity = 2) {
    cap = capacity;
    currentTimepoint = 0;
    toReplaceTimepoint = 0;
  }
  int get(int key) {
    if (dict.count(key) > 0){
      pair<int, int> value_preTimepoint = dict[key];
      updateHistory(key, value_preTimepoint);
      dict[key] = value_preTimepoint;
      return value_preTimepoint.first;
    }
    return -1;
  }
  void put(int key, int value) {
    if (dict.count(key) > 0){
      pair<int, int> value_preTimepoint = dict[key];
      updateHistory(key, value_preTimepoint);
      value_preTimepoint.first = value;
      dict[key] = value_preTimepoint;
      return;
    } else if (dict.size() >= cap){
      while (history.count(toReplaceTimepoint) == 0)
        toReplaceTimepoint++;
      int toReplaceKey = history[toReplaceTimepoint];
      history.erase(toReplaceTimepoint++);
      dict.erase(toReplaceKey);
    }
    pair<int, int> value_curTimepoint(value, currentTimepoint);
    dict[key] = value_curTimepoint;
    history[currentTimepoint++] = key;
  }
  string run(int p){
    vector<int> ans;
    put(1, 1);
    put(2, 2);
    ans.push_back(get(1));
    put(3, 3);
    ans.push_back(get(2));
    put(4, 4);
    ans.push_back(get(1));
    ans.push_back(get(3));
    ans.push_back(get(4));
    string res;
    for (int i = 0; i < ans.size(); i++) {
      res += to_string(ans[i]) + "#" ;
    }
    return res;
  }
};


int main(){
  LRUCache sol;
  vector<int> inputs = {1};
  vector<string> ans = {"1#-1#-1#3#4#"};
  QuickCheck<int, string, LRUCache> q(inputs, ans);
  q.runTests();
  return 0;
}
