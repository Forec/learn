#include <iostream>
#include <string>

using namespace std;

class SUNDAY{
public:
  static int search(string text, string pattern){
    int i = 0, j = 0;
    int pe = pattern.length() - 1;
    int tb = i, te = text.length() - 1;
    while ( i < text.length() && j < pattern.length()){
      if (text[i] == pattern[j]){
        i++;
        j++;
      } else {
        int k = pattern.length() - 1;
        while (k >= 0 && text[pe + 1] != pattern[k])
          k--;
        int gap = pattern.length() - k;
        i += gap;
        pe = i + pattern.length() - 1;
        tb = i;
        j = 0;
      }
    }
    if (i <= text.length())
      return tb;
    return -1;
  }
};

int main(){
  cout << SUNDAY::search("I WANT TO A SOFTWARE FOR ", "SOFTWARE") << endl;
  return 0;
}
