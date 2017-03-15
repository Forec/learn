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

class Trie {
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
    for (int i = 0; i < _root->child.size(); i++){
      if (_root->child[i]->c == word[0])
        return _search(_root->child[i], word.substr(1));
    }
    return false;
  }
  bool _starts(TrieTreeNode *_root, string word){
    if (word.length() == 0){
      return true;
    }
    if (_root == NULL)
      return false;
    for (int i = 0; i < _root->child.size(); i++){
      if (_root->child[i]->c == word[0])
        return _starts(_root->child[i], word.substr(1));
    }
    return false;
  }
public:
  Trie() {
    root = new TrieTreeNode('0');
  }
  void insert(string word) {
    _insert(root, word);
  }
  bool search(string word) {
    return _search(root, word);
  }
  bool startsWith(string prefix) {
    return _starts(root, prefix);
  }
};

int main(){
  Trie t;
  t.insert("fuck");
  t.insert("shit");
  t.insert("fuckp");
  cout << (t.search("fuck") == 1) << endl;
  cout << (t.search("fuckp") == 1) << endl;
  cout << (t.startsWith("fuc") == 1) << endl;
  cout << (t.startsWith("fac") == 0) << endl;
  cout << (t.search("shit") == 1) << endl;
  return 0;
}
