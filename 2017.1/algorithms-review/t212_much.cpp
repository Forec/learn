#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool cmp(const string &a, const string &b){
  int size = a.size() < b.size() ? a.size() : b.size();
  for (unsigned int i = 0; i < size; i++){
    if (a[i] != b[i]){
      if (a.size() != b.size())
        return a.size() < b.size();
      return a[i] < b[i];
    }
  }
  return a.size() < b.size();
}

class Solution {
private:
  struct TrieTreeNode {
    char ch;
    TrieTreeNode* childs[26];
    TrieTreeNode(): ch(0) {};
    TrieTreeNode(char c): ch(c) {};
  };
  class Trie{
  private:
    TrieTreeNode * guard;
    void _insert(string word, TrieTreeNode * root){
      if (word.length() == 0)
        return;
      char code = word[0];
      if (root->childs[code - 'a'] == NULL){
        root->childs[code - 'a'] = new TrieTreeNode(code);
      }
      _insert(word.substr(1), root->childs[code - 'a']);
    }
    bool _search(string word, TrieTreeNode * root){
      if (word.length() == 0)
        return true;
      if (root == NULL)
        return false;
      char code = word[0];
      if (root->childs[code - 'a'] == NULL)
        return false;
      return _search(word.substr(1), root->childs[code - 'a']);
    }
    void _destroy(TrieTreeNode* root){
      if (root == NULL)
        return;
      for (unsigned short i = 0; i < 26; i++){
        if (root->childs[i] != NULL)
          _destroy(root->childs[i]);
      }
      delete root;
    }
  public:
    Trie() {
      guard = new TrieTreeNode();
    }
    ~Trie() {
      if (guard != NULL){
        delete guard;
      }
    }
    void destroy(){
      _destroy(guard);
      guard = new TrieTreeNode();
    }
    void insert(string word){
      if (guard == NULL)
        guard = new TrieTreeNode();
      _insert(word, guard);
    }
    bool search(string word){
      return guard != NULL && _search(word, guard);
    }
  };
  bool dict[26][26];
  int m, n;
  int dx[4] = {-1, 0, 1, 0};
  int dy[4] = {0, -1, 0, 1};
  bool dfs(vector<vector<char>> &board,
           vector<vector<bool>> &visit,
           unsigned int x, unsigned int y,
           string word, string build,
           Trie& tree){
    if (word.length() == 0)
      return true;
    if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] != word[0] || visit[x][y])
      return false;
    build += word.substr(0, 1);
    tree.insert(build);
    word = word.substr(1);
    visit[x][y] = true;
    bool find = false;
    for (unsigned short i = 0; i < 4 && !find; i++){
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= m || ny >= m ||
          (word.length() >= 1 && board[nx][ny] != word[0]) || visit[nx][ny]){
        continue;
      }
      find = find || dfs(board, visit, nx, ny, word, build, tree);
    }
    //    if (!find)
    visit[x][y] = false;
    cout << word << " " << x << " " << y << " " << build << " " << find << endl;
    return find;
  }
  unsigned int cmpSamePrefix(const string & a, const string &b){
    unsigned int size = a.size() < b.size() ? a.size() : b.size();
    for (unsigned int i = 0; i < size; i++)
      if (a[i] != b[i])
        return i;
    return size;
  }
  bool lookup(string word, string alreadyBuild,
              vector<vector<char>> &board,
              vector<vector<bool>> &visit,
              Trie & tree){
    if (word.length() == 0)
      return true;
    char code = word[0];
    bool checkFinished = false;
    for (int i = 0; i < m && !checkFinished; i++){
      for (int j = 0; j < n && !checkFinished; j++){
        if (code == board[i][j]){
          if (dfs(board, visit, i, j, word, alreadyBuild, tree)){
            checkFinished = true;
          } else {
            tree.destroy();
          }
        }
      }
    }
    return checkFinished;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    for (unsigned int i = 0; i < words.size(); i++){
      for (unsigned int j = 0; j < words[i].length() - 1; j++){
        dict[words[i][j] - 'a'][words[i][j+1] - 'a'] = true;
      }
    }
    sort(words.begin(), words.end(), cmp);

    vector<string> result;
    int ignoreEmptyString = 0;
    for (ignoreEmptyString = 0;
         ignoreEmptyString < words.size() && words[ignoreEmptyString].length() == 0;
         ignoreEmptyString++)
      result.push_back(words[ignoreEmptyString]);
    words.erase(words.begin(), words.begin() + ignoreEmptyString);

    if (board.size() == 0 || board[0].size() == 0)
      return result;
    m = board.size(); n = board[0].size();

    Trie tree;
    vector<vector<bool>> visit(m, vector<bool>(n, false));
    if (lookup(words[0], "", board, visit, tree))
      result.push_back(words[0]);

    for (int index = 1; index < words.size(); index++){
      // int samePrefixLength = cmpSamePrefix(words[index-1], words[index]);
      // if (samePrefixLength < 4 && words[index-1].length() > 6){
      //   tree.destroy();
      //   samePrefixLength = 0;
      // }
      string toSearch = words[index];//.substr(samePrefixLength);
      int samePrefixLength = 0;
      if (lookup(toSearch, words[index].substr(0, samePrefixLength), board, visit, tree))
        result.push_back(words[index]);
    }
    return result;
  }
};

int main(){
  Solution sol;
  vector<vector<char>> map = {{'o','a','a','n'},
                              {'e','t','a','e'},
                              {'i','h','k','r'},
                              {'i','f','l','v'}};
  vector<string> words {"oath","pea","eat","rain"};
  vector<string> ans = sol.findWords(map, words);
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
