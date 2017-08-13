#include <iostream>
#include <vector>

#define MAXN 1000

using namespace std;

int visited[MAXN]; // initialized to false, indicate whether a node has been dfs
int parent[MAXN]; // used to record the parent of nodes, parent[i] initialized to i
Node **list; // list stores the offline questions

void tarjan(Node * root){
  if (root == NULL || visited[root->val])
    return;
  int u = root->val;
  visited[u] = 1;
  Node *q = list[u]; // the questions in format (u, v) or (v, u)
  while (q != NULL){ // this loop is used to solve problems
    if (visited[q->v])
      q->ans = find(q->v);
    q = q->next;
  }
  if (root->left != NULL && !visited[root->left->val]){
    tarjan(root->left);
    parent[root->left->val] = u;
  }
  if (root->right != NULL && !visited[root->right->val]){
    trajan(root->right);
    parent[root->right->val] = u;
  }
}
