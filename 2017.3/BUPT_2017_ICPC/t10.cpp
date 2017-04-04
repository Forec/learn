#include <iostream>
#include <vector>

using namespace std;

const int N = 1024;
int dfn[N], low[N], S[N], vis[N];
int times, top, n, m, res;

struct Edge {
  int u, v;
  Edge(int _u, int _v) : u(_u), v(_v){};
  Edge(){};
};

Edge edges[5001];

struct Node {
  int v;
  struct Node *next;
  Node(int _v): v(_v), next(NULL){};
};

inline int min(int x, int y){
  return x < y ? x : y;
}

void insert(Node ** graph, int u, int v){
  Node *tmp = new Node(v);
  tmp->next = graph[u];
  graph[u] = tmp;
}

void remove(Node ** graph, int u){
  Node *tmp = graph[u];
  if (tmp == NULL)
    return;
  graph[u] = tmp->next;
  delete tmp;
}

void init(){
  res = 0;
  top = 0; times = 0;
  for (int i = 0; i < n; i++)
    vis[i] = 0;
}

void tarjan(Node **graph, int u){
  ++times;
  dfn[u] = times;
  low[u] = times;
  S[top++] = u;
  vis[u] = 1;
  Node * tmp = graph[u];
  while (tmp != NULL){
    if (vis[tmp->v] == 0){
      tarjan(graph, tmp->v);
      low[u] = min(low[u], low[tmp->v]);
    }
    if (vis[tmp->v] == 1){
      low[u] = min(low[u], dfn[tmp->v]);
    }
    tmp = tmp->next;
  }
  if (dfn[u] == low[u]){
    vector<int> nodes;
    while (S[--top] != u){
      nodes.push_back(S[top]);
      vis[S[top]] = 2;
    }
    nodes.push_back(u);
    if (nodes.size() != 1){
      res += (nodes.size() * (nodes.size() -1) / 2);
    }
  }
}

Node **buildGraph(){
  Node ** list = new Node*[n];
  for (int i = 0; i < n; i++)
    list[i] = NULL;
  int u, v;
  for (int i = 0; i < m; i++){
    cin >> u >> v;
    edges[i] = Edge(u-1, v-1);
    insert(list, u-1, v-1);
  }
  return list;
}

void destroyGraph(Node ** graph){
  for (int i = 0; i < n; i++){
    Node *tmp = graph[i],  *pre;
    while (tmp != NULL){
      pre = tmp;
      tmp = tmp->next;
      delete pre;
    }
  }
  delete []graph;
}

int main(){
  int t;
  cin >> t;
  while (t --){
    cin >> n >> m;
    Node ** graph = buildGraph();
    int ans = 0;
    for (int i = 0; i < m; i++){
      init();
      Edge e = edges[i];
      int u = e.u, v = e.v;
      insert(graph, v, u);
      for (int i = 0; i < n; i++){
        if (vis[i] == 0)
          tarjan(graph, i);
      }
      if (res > ans)
        ans = res;
      remove(graph, v);
    }
    cout << ans << endl;
    destroyGraph(graph);
  }
  return 0;
}
