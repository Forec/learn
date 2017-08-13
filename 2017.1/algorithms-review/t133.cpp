#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
private:
  UndirectedGraphNode *_cloneGraph(UndirectedGraphNode *node, unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> & dict) {
    if (node == NULL)
      return NULL;
    if (dict.count(node) > 0)
      return dict[node];
    UndirectedGraphNode * src = new UndirectedGraphNode(node->label);
    dict[node] = src;
    for (int i = 0; i < node->neighbors.size(); i++){
      src->neighbors.push_back(_cloneGraph(node->neighbors[i], dict));
    }
    return src;
  }
public:
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> dict;
    return _cloneGraph(node, dict);
  }
  string serialize(UndirectedGraphNode *node){
    if (node == NULL){
      return "";
    }
    string s = to_string(node->label);
    for (int i = 0;i < node->neighbors.size(); i++){
      s += (", " + to_string(node->neighbors[i]->label));
    }
    s += "#";
    return s;
  }
};


int main(){
  UndirectedGraphNode * n1 = new UndirectedGraphNode(0);
  UndirectedGraphNode * n2 = new UndirectedGraphNode(1);
  UndirectedGraphNode * n3 = new UndirectedGraphNode(2);
  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n3);
  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n3);
  Solution sol;
  UndirectedGraphNode * ans = sol.cloneGraph(n1);
  cout << (sol.serialize(n1) == sol.serialize(ans) ) << endl;
  return 0;
}

