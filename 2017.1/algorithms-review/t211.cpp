#include <iostream>
#include <vector>
#include <string>

using namespace  std;

struct TrieTreeNode {
  char c;
  vector<TrieTreeNode *> child;
  bool end;
  TrieTreeNode(char _c) : c(_c), end(false) {
    child = vector<TrieTreeNode *>();
  };
};

class WordDictionary {
private:
  TrieTreeNode * root;
  TrieTreeNode * _insert(TrieTreeNode *_root, string word){
    if (word.length() == 0){
      if (_root != NULL)
        _root->end = true;
      return _root;
    }
    if (_root == NULL)
      _root = new TrieTreeNode('0');
    for (int i = 0; i < _root->child.size(); i++){
      if (_root->child[i]->c == word[0]){
        _insert(_root->child[i], word.substr(1));
        return _root;
      }
    }
    TrieTreeNode * newNode = new TrieTreeNode(word[0]);
    _root->child.push_back(newNode);
    _insert(newNode, word.substr(1));
    return _root;
  }
  bool _search(TrieTreeNode *_root, string word){
    if (word.length() == 0){
      if (_root == NULL || _root->end == true)
        return true;
      return false;
    }
    if (_root == NULL)
      return false;
    if (word[0] != '.'){
      for (int i = 0; i < _root->child.size(); i++){
        if (_root->child[i]->c == word[0])
          return _search(_root->child[i], word.substr(1));
      }
    } else {
      for (int i = 0; i < _root->child.size(); i++){
        if (_search(_root->child[i], word.substr(1)))
          return true;
      }
    }
    return false;
  }
public:
  WordDictionary() {
    root = new TrieTreeNode('0');
  }
  void addWord(string word) {
    _insert(root, word);
  }
  bool search(string word) {
    return _search(root, word);
  }
};

int main(){
  WordDictionary t;
  t.addWord("bad");
  t.addWord("dad");
  t.addWord("mad");
  cout << (t.search("pad") == 0) << endl;
  cout << (t.search("bad") == 1) << endl;
  cout << (t.search(".ad") == 1) << endl;
  cout << (t.search("b.a") == 0) << endl;
  cout << (t.search("d..") == 1) << endl;
  return 0;
}
