#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
private:
  int change(string &tp){
    int j = 0;
    for (j = 0; j < tp.length();j ++)
      if (tp[j] == ':')
        break;
    string hour = tp.substr(0, j);
    string minute = tp.substr(j+1);
    int h, m;
    stringstream ssh;
    ssh << hour;
    ssh >> h;
    stringstream ssm;
    ssm << minute;
    ssm >> m;
    return h * 60 + m;
  }
public:
  int findMinDifference(vector<string>& timePoints) {
    vector<int> minutes;
    for (int i = 0; i < timePoints.size(); i++){
      minutes.push_back(change(timePoints[i]));
    }
    sort(minutes.begin(), minutes.end());
    minutes.insert(minutes.end(), minutes.begin(), minutes.end());
    int minx = 24*60-1;
    for (int i = 0; i < minutes.size() -1; i++){
      int gap = abs(minutes[i+1] - minutes[i]);
      if (gap > 720)
        gap = 1440 - gap;
      minx = minx > gap ? gap : minx;
      if (minx == 0)
        return 0;
    }
    return minx;
  }
};

int main(){
  vector<string> inputs = {"23:59","00:00"};
  vector<string> inputs2 = {"23:59","12:00", "13:49"};
  vector<string> inputs3 = {"05:31","22:08","00:35"};
  Solution sol;
  cout <<(sol.findMinDifference(inputs3)==147) << endl;
  cout <<(sol.findMinDifference(inputs)==1) << endl;
  cout <<(sol.findMinDifference(inputs2)==109) << endl;
  return 0;
}
