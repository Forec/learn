#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    int st = newInterval.start, ed = newInterval.end;
    vector<Interval> left, right;
    for (vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++){
      if (it->end < st)
        left.push_back(*it);
      else if (it->start > ed)
        right.push_back(*it);
      else {
        st = min(st, it->start);
        ed = max(ed, it->end);
      }
    }
    left.push_back(Interval(st, ed));
    left.insert(left.end(), right.begin(), right.end());
    return left;
  }
};

int main(){
  vector<Interval> para = {Interval(1, 2), Interval(3, 5), Interval(6, 7), Interval(8, 10), Interval(12, 16)};
  Solution sol;
  vector<Interval> ans = sol.insert(para, Interval(4, 9));
  for (int i = 0; i < ans.size(); i ++){
    cout << ans[i].start << "-" << ans[i].end << endl;
  }
  cout << endl;
}
