#include <iostream>
#include <string>
#include <unordered_map>


using namespace std;

class BM {
public:
  static int search(string text, string pattern){
    unordered_map<char, int> jump;
    for (int i = 0; i < text.length(); i++)
      jump[text[i]] = pattern.length();
    for (int i = 0; i < pattern.length(); i++){
      jump[pattern[i]] = pattern.length() - i - 1;
    }
    int utext = pattern.length() - 1;
    int upat = pattern.length();
    while (utext < text.length() && upat != 0){
      if (text[utext] == pattern[upat - 1]){
        utext --;
        upat --;
      } else {
        utext = utext + jump[text[utext]];
        upat = pattern.length();
      }
    }
    if (upat == 0)
      return utext + 1;
    return -1;
  }
};

int main(){
  cout << BM::search("I want to write a software fucking", "software") << endl;
  return 0;
}
