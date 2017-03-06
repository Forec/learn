#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include "test/quickcheck.h"

using namespace std;

struct Para{
  string beginWord;
  string endWord;
  vector<string> wordList;
  friend ostream& operator << (ostream &os, Para & p){
    os << "beginWord: " << p.beginWord << ", endWord: " << p.endWord <<
      ", wordList: [" ;
    if (p.wordList.size() != 0){
      cout << p.wordList[0];
      for (int i = 1; i < p.wordList.size(); i++){
        cout << ", " <<p.wordList[i] ;
      }
    }
    cout << "]";
    return os;
  }
};

struct Ans {
  vector<vector<string>> ls;
  bool  operator == (const Ans & b){
    if (ls.size() != b.ls.size())
      return false;
    vector<bool> used(ls.size(), false);
    for (int i =0; i < ls.size(); i++){
      bool find = false;
      for (int j = 0; j < b.ls.size(); j++){
        if (used[j])
          continue;
        if (b.ls[j] == ls[i]){
          used[j] = true;
          find = true;
          break;
        }
      }
      if (!find)
        return false;
    }
    return true;
  }
  static void print(vector<string> &ss){
    cout << "[";
    if (ss.size() != 0){
      cout << ss[0];
      for (int i = 1; i < ss.size(); i++)
        cout << ", " << ss[i];
    }
    cout << "]";
  }
  friend ostream &operator << (ostream &os, Ans &p){
    os << "[";
    if (p.ls.size() > 0){
      print(p.ls[0]);
      for (int i = 1; i < p.ls.size(); i++){
        cout << ",\n";
        print(p.ls[i]);
      }
    }
    os << "]";
    return os;
  }
};

class Solution {
private:
  struct Node {
    int num;
    int weight;
    Node * next;
    Node(int index): num(index), weight(0), next(NULL) {};
  };
  struct QNode {
    int currentNumber;
    vector<int> link;
    vector<bool> used;
    QNode (int index): currentNumber(index){
      link.clear();
      used.clear();
    }
  };
  int maxWordLen;
  int nodes, st, ed;
  vector<string> filter;
  int calcDistance(string word1, string word2){
    // since ladderLength has ensured that word1 must have the same length with word2, there
    // is an assert here.
    assert(word1.length() == word2.length());
    int diff = 0;
    for (int i = 0; i < word1.length(); i++){
      if (word1[i] != word2[i]){
        if (diff >= 1)
          return maxWordLen;
        diff ++;
      }
    }
    return diff;
  }

  vector<string> generate(vector<int> & link){
    vector<string> res;
    for (int i = 0; i <link.size(); i++)
      res.push_back(filter[link[i]]);
    return res;
  }

  vector<vector<string>> bfs(vector<Node *> & list){
    queue<QNode *> q;
    QNode *s = new QNode(st);
    vector<int> l = {st};
    vector<bool> u(nodes, false);
    vector<vector<string>> result;
    u[st] = true;
    s->link = l; s->used = u;
    q.push(s);
    int maxSteps = maxWordLen;
    while (!q.empty()){
      QNode * cur = q.front();
      q.pop();
      int curs = cur->currentNumber;
      if (cur->link.size() >maxSteps)
        break;
      if (curs == ed){
        result.push_back(generate(cur->link));
        if (maxSteps > cur->link.size()){
          maxSteps = cur->link.size();
        }
      }
      Node *p = list[curs]->next;
      while (p){
        //        cout << curs << " " << p->num << " " << cur->used[p->num] << endl;
        if (cur->used[p->num] == false){
          QNode * qm = new QNode(p->num);
          qm->used = cur->used;
          qm->used[p->num] = true;
          qm->link = cur->link;
          qm->link.push_back(p->num);
          q.push(qm);
        }
        p = p->next;
      }
    }
    return result;
  }

public:
 vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    int wordLen = beginWord.length();
    if (wordLen != endWord.length())// word length are not matched
      return vector<vector<string>>();
    maxWordLen = wordLen * wordList.size();
    int n = wordList.size();
    unordered_map<string, int> dict;
    filter.clear();

    st = -1, ed = -1;
    int index = 0;
    for (vector<string>::iterator it = wordList.begin(); it!= wordList.end(); it++){
      if (wordLen != it->length())
        continue;
      filter.push_back(*it);
      dict[*it] = index;
      if (beginWord == *it){
        st = index;
      }
      if (endWord == *it){
        ed = index;
      }
      index++;
    }
    if (ed == -1)// endword not in list, cannot reach
      return vector<vector<string>>();
    n = index; // filter the invalid words
    if (st == -1){
      dict[beginWord] = n;
      st = n;
      filter.push_back(beginWord);
      n++;
    }

    vector<Node*> list(n, NULL);
    for (int i = 0; i < n; i++){
      list[i] = new Node(i);
    }
    for (int i = 0; i < n; i++){
      for (int j = i+1; j < n; j++){
        if (calcDistance(filter[i], filter[j]) == 1){
          Node *u = new Node(i);
          Node *v = new Node(j);
          u->weight = 1;
          v->weight = 1;
          u->next = list[j]->next;
          list[j]->next = u;
          v->next = list[i]->next;
          list[i]->next = v;
        }
      }
    }

    nodes = n;
    return bfs(list);
  }
  Ans run(Para p){
    vector<vector<string>> ans =  findLadders(p.beginWord, p.endWord, p.wordList);
    Ans a;
    a.ls = ans;
    return a;
  }
};


int main(){
  Solution sol;
  vector<string> beginWords = {"hit"};//, "sail"};
  vector<string> endWords = {"cog"};//, "ruip"};
  vector<vector<string>> wordLists = {{"hot","dot","dog","lot","log","cog"}};//,
  //                                      {"rain","ruin","gain","ruip","grin","grit","sail","main","pain","pair","pail","mail"}};
  vector<Para> paras;
  for (int i = 0; i < beginWords.size(); i++){
    Para p;
    p.beginWord = beginWords[i];
    p.endWord = endWords[i];
    p.wordList = wordLists[i];
    paras.push_back(p);
  }
  vector<vector<string>> ans = {{"hit","hot","dot","dog","cog"},
                                {"hit","hot","lot","log","cog"}};
  Ans a;
  a.ls = ans;
  vector<Ans> results = {a};
  QuickCheck<Para, Ans, Solution> *q = new QuickCheck<Para, Ans, Solution>(paras, results);
  q->runTests();
  // vector<vector<string>> res =  sol.findLadders(beginWords[0], endWords[0], wordLists[0]);
  // for (int i = 0; i < res.size(); i++){
  //   for (int j = 0; j < res[i].size(); j++){
  //     cout << res[i][j] << " ";
  //   }
  //   cout << endl;
  //  }
  return 0;
}
