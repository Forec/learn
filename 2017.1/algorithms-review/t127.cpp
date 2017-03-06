#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
//#include <queue>
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

class Solution {
private:
  struct Node {
    int num;
    int weight;
    Node * next;
    Node(int index): num(index), weight(0), next(NULL) {};
  };
  int maxWordLen;
  int nodes, st, ed;

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

  int Dijkstra(vector<Node*> & list){
    vector<int> dist(nodes, maxWordLen);
    dist[st] = 0;
    vector<bool> used(nodes, false);
    for (int i = 0; i < nodes; i++){
      int minJ = -1, minD = maxWordLen;
      for (int j = 0; j < nodes; j++){
        if (used[j])
          continue;
        if (dist[j] < minD){
          minD = dist[j];
          minJ = j;
        }
      }
      if (minJ == -1)
        break;
      used[minJ] = true;
      int s = minJ;
      Node * v = list[s]->next;
      while (v != NULL){
        if (dist[v->num] > dist[s] + v->weight){
          dist[v->num] = dist[s] + v->weight;
        }
        v = v->next;
      }
    }
    if (dist[ed] < maxWordLen)
      return dist[ed] + 1;
    return 0;
  }

public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int wordLen = beginWord.length();
    if (wordLen != endWord.length())// word length are not matched
      return 0;
    maxWordLen = wordLen * wordList.size();
    int n = wordList.size();
    unordered_map<string, int> dict;
    vector<string> filter;

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
      return 0;
    n = index; // filter the invalid words
    if (st == -1){
      dict[beginWord] = n;
      st = n;
      filter.push_back(beginWord);
      n++;
    }

    // use adjacent table
    //    vector<vector<int>> graph(n, vector<int>(n, 0));
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

    // for (int i =0 ; i < n;i ++){
    //   cout << "(" << i << ")" << filter[i] << ": ";
    //   Node * nx = list[i]->next;
    //   while (nx!=NULL){
    //     cout << " -> " << nx->num;
    //     nx = nx->next;
    //   }
    //   cout << endl;
    // }

    nodes = n;
    return Dijkstra(list);
  }
  int run(Para p){
    return ladderLength(p.beginWord, p.endWord, p.wordList);
  }
};


int main(){
  Solution sol;
  vector<string> beginWords = {"hit", "sail"};
  vector<string> endWords = {"cog", "ruip"};
  vector<vector<string>> wordLists = {{"hot","dot","dog","lot","log","cog"},
                                      {"rain","ruin","gain","ruip","grin","grit","sail","main","pain","pair","pail","mail"}};
  vector<Para> paras;
  for (int i = 0; i < beginWords.size(); i++){
    Para p;
    p.beginWord = beginWords[i];
    p.endWord = endWords[i];
    p.wordList = wordLists[i];
    paras.push_back(p);
  }
  vector<int> ans = {5, 6};
  QuickCheck<Para, int, Solution> *q = new QuickCheck<Para, int, Solution>(paras, ans);
  q->runTests();
  //    cout << sol.ladderLength(beginWords[1], endWords[1], wordLists[1]) << endl;
  return 0;
}
