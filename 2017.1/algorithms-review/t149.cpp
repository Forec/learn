#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

vector<vector<int>> aTestCase = {{40,-23},{9,138},{429,115},{50,-17},{-3,80},{-10,33},{5,-21},{-3,80},{-6,-65},{-18,26},{-6,-65},{5,72},{0,77},{-9,86},{10,-2},{-8,85},{21,130},{18,-6},{-18,26},{-1,-15},{10,-2},{8,69},{-4,63},{0,3},{-4,40},{-7,84},{-8,7},{30,154},{16,-5},{6,90},{18,-6},{5,77},{-4,77},{7,-13},{-1,-45},{16,-5},{-9,86},{-16,11},{-7,84},{1,76},{3,77},{10,67},{1,-37},{-10,-81},{4,-11},{-20,13},{-10,77},{6,-17},{-27,2},{-10,-81},{10,-1},{-9,1},{-8,43},{2,2},{2,-21},{3,82},{8,-1},{10,-1},{-9,1},{-12,42},{16,-5},{-5,-61},{20,-7},{9,-35},{10,6},{12,106},{5,-21},{-5,82},{6,71},{-15,34},{-10,87},{-14,-12},{12,106},{-5,82},{-46,-45},{-4,63},{16,-5},{4,1},{-3,-53},{0,-17},{9,98},{-18,26},{-9,86},{2,77},{-2,-49},{1,76},{-3,-38},{-8,7},{-17,-37},{5,72},{10,-37},{-4,-57},{-3,-53},{3,74},{-3,-11},{-8,7},{1,88},{-12,42},{1,-37},{2,77},{-6,77},{5,72},{-4,-57},{-18,-33},{-12,42},{-9,86},{2,77},{-8,77},{-3,77},{9,-42},{16,41},{-29,-37},{0,-41},{-21,18},{-27,-34},{0,77},{3,74},{-7,-69},{-21,18},{27,146},{-20,13},{21,130},{-6,-65},{14,-4},{0,3},{9,-5},{6,-29},{-2,73},{-1,-15},{1,76},{-4,77},{6,-29}};

vector<vector<int>> aTestCase2 = {{1,1}, {1,1}, {1,1}};


bool cmp(const Point &a, const Point &b){
  if (a.x != b.x)
    return a.x < b.x;
  return a.y < b.y;
}

class Solution {
public:
  int maxPoints(vector<Point>& _points) {
    int n  = _points.size();
    int pre = 0, cur = 0;
    vector<Point> points;
    vector<int> duplicatedCount;

    // remove duplicated points
    sort(_points.begin(), _points.end(), cmp);
    while (pre < n){
      while (cur < n && _points[cur].x == _points[pre].x && _points[cur].y == _points[pre].y){
        cur++;
      }
      duplicatedCount.push_back(cur - pre);
      points.push_back(_points[pre]);
      pre = cur;
    }
    n = points.size();

    // if there are less than 2 distinct points, just sum them up.
    int result = 2;
    if (n <= 2){
      result = 0;
      for (int i = 0; i < n; i++){
        result += duplicatedCount[i];
      }
      return result;
    }

    // f[i][j] == True indicates the line decided by points[i] and points[j] has been calculated.
    vector<vector<bool>> f(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++){
      for (int j = i + 1 ; j < n; j++){
        if (f[i][j])
          continue;
        f[i][j] = true;
        bool shouldBreak;
        vector<int> currentLine = {i, j};
        Point anotherPoint = points[j];

        // long long since x_*y or y_*x may overflow
        long long y = anotherPoint.y - points[i].y;
        long long x = anotherPoint.x - points[i].x;
        for (int k = j + 1; k < n; k++){
          long long y_ = points[k].y - points[i].y;
          long long x_ = points[k].x - points[i].x;
          if (x_* y == y_ * x){
            currentLine.push_back(k);
          } else {
            continue;
          }
          shouldBreak = false;
          for (vector<int>::iterator it = currentLine.begin(); it != currentLine.end() - 1; it++){
            // it should up to currentLine.end() - 1 since `k` has been pushed into currentLine before.
            if (f[*it][k]){
              shouldBreak = true;
              break;
            }
            f[*it][k] = true;
          }
          if (shouldBreak)
            break;
        }
        if (shouldBreak)
          break;
        int pointsOnCurrentLine = 0;
        for (vector<int>::iterator it = currentLine.begin(); it != currentLine.end(); it++)
          pointsOnCurrentLine += duplicatedCount[*it];
        if (pointsOnCurrentLine > result)
          result = pointsOnCurrentLine;
      }
    }
    return result;
  }
};

int main(){
  Solution sol;
  vector<Point> para;
  for (int i = 0; i < aTestCase.size(); i++){
    para.push_back(Point(aTestCase[i][0], aTestCase[i][1]));
  }
  cout << sol.maxPoints(para) << endl;
  return 0;
}
