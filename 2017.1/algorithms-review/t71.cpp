#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
  vector<string> splitBySlash(string path){
    vector<string> result;
    int pre = 0;
    while (path[pre] == '/') pre++;
    while (pre < path.length()){
      size_t found = path.find_first_of('/', pre);
      if (found == string::npos){
        result.push_back(path.substr(pre));
        return result;
      } else {
        result.push_back(path.substr(pre, found - pre));
        pre = found+1;
        while (pre < path.length() && path[pre] == '/') pre++;
      }
    }
    return result;
  }
public:
  string simplifyPath(string path) {
    vector<string> parts = splitBySlash(path);
    vector<string> filter;
    for (vector<string>::iterator it = parts.begin(); it != parts.end(); it++){
      if ((*it) == "."){
        continue;
      } else if ((*it) == ".."){
        if (!filter.empty()){
          filter.pop_back();
        }
      } else
        filter.push_back(*it);
    }
    stringstream ss;
    for (vector<string>::iterator it = filter.begin(); it != filter.end(); it++){
      ss << '/' << *it;
    }
    if (filter.size() == 0)
      ss << '/';
    return ss.str();
  }
};

int main(){
  Solution sol;
  cout << sol.simplifyPath("/../") << endl;
  cout << sol.simplifyPath("/home//foo/") << endl;
  cout << sol.simplifyPath("/home/") << endl;
  cout << sol.simplifyPath("/a/./b/../../c/") << endl;
  return 0;
}
