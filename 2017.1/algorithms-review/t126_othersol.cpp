#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
#include <unordered_map>
#include <unordered_set>
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
public:
    std::vector<std::vector<std::string> > findLadders(std::string beginWord, std::string endWord, vector<std::string> &wordList) {
      unordered_set<string> dict;
      for (int i = 0; i < wordList.size(); i++)
        dict.insert(wordList[i]);
      std::vector<std::vector<std::string> > paths;
      if (dict.find(endWord) == dict.end())
        return paths;
      std::vector<std::string> path(1, beginWord);
      if (beginWord == endWord) {
        paths.push_back(path);
        return paths;
      }
        std::unordered_set<std::string> words1, words2;
		words1.insert(beginWord);
		words2.insert(endWord);
		std::unordered_map<std::string, std::vector<std::string> > nexts;
		bool words1IsBegin = false;
        if (findLaddersHelper(words1, words2, dict, nexts, words1IsBegin))
			getPath(beginWord, endWord, nexts, path, paths);
		return paths;
    }
private:
    bool findLaddersHelper(
		std::unordered_set<std::string> &words1,
		std::unordered_set<std::string> &words2,
		std::unordered_set<std::string> &dict,
		std::unordered_map<std::string, std::vector<std::string> > &nexts,
		bool &words1IsBegin) {
		words1IsBegin = !words1IsBegin;
		if (words1.empty())
            return false;
		if (words1.size() > words2.size())
			return findLaddersHelper(words2, words1, dict, nexts, words1IsBegin);
		for (auto it = words1.begin(); it != words1.end(); ++it)
			dict.erase(*it);
		for (auto it = words2.begin(); it != words2.end(); ++it)
			dict.erase(*it);
        std::unordered_set<std::string> words3;
		bool reach = false;
        for (auto it = words1.begin(); it != words1.end(); ++it) {
			std::string word = *it;
			for (auto ch = word.begin(); ch != word.end(); ++ch) {
				char tmp = *ch;
                for (*ch = 'a'; *ch <= 'z'; ++(*ch))
					if (*ch != tmp)
						if (words2.find(word) != words2.end()) {
							reach = true;
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
						}
						else if (!reach && dict.find(word) != dict.end()) {
							words3.insert(word);
							words1IsBegin ? nexts[*it].push_back(word) : nexts[word].push_back(*it);
                        }
				*ch = tmp;
            }
        }
        return reach || findLaddersHelper(words2, words3, dict, nexts, words1IsBegin);
    }
	void getPath(
		std::string beginWord,
		std::string &endWord,
		std::unordered_map<std::string, std::vector<std::string> > &nexts,
		std::vector<std::string> &path,
		std::vector<std::vector<std::string> > &paths) {
		if (beginWord == endWord)
			paths.push_back(path);
		else
			for (auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it) {
				path.push_back(*it);
				getPath(*it, endWord, nexts, path, paths);
				path.pop_back();
			}
	}
public:
  Ans run(Para p){
    vector<vector<string>> ans = findLadders(p.beginWord, p.endWord, p.wordList);
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
