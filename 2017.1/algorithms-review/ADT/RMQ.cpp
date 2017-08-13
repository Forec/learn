// Several methods solving RMQ
// * brute-force, O(qn), where q is the number of questions, online
// * Interval Tree, O(n) - O(qlogn), online
// * ST, which is a DP solution, O(nlogn) - O(q), where O(nlogn) is used for initialization, online
// * LCA -> stricted to RMA, online, O(n) - O(q), online

/*
  ST DP solution: Consider the RMQ Minimal Problem, use F[i][j] represents the minimal number between range [i..i + 2^j - 1], here '[]' means the range is closed, and '()' means the range is opened. For example, F[2][4] stores the minimal value in range [2, 2+ 2^4 -1], which is just [2, 17]. Notice that F[i][0] is always data[i]. Since the range [i..i+ 2^j -1] has even length when j >= 1, we can seperate it into two ranges: [i..i + 2^(j-1) - 1] and [i+ 2^(j-1), i+ 2^j -1]. It is obviously that the minimal value is F[i][j] = min(F[i][j-1], F[i+ 2^(j-1)][j-1]). The formula is similar for Maximal problem, just replace 'min' with 'max'.
  Now we have calculated matrix F, ST can use O(1) to query for each question.
  Let a question be (LOW, HIGH). We can calculate k = [log(H - L + 1, 2)], here '[]' means floor. so LOW + 2^ k <= HIGH, HIGH - 2^k >= LOW, and HIGH - 2^k <= LOW + 2^k. So range [LOW, LOW+ 2^k - 1] and range [HIGH - 2^k +1, HIGH] covers [LOW, HIGH], so we can get ANS = min(F[LOW][k], F[HIGH-2^k+1][k]).
 */
#include <iostream>
#include <cmath>
#include <vector>
class RMQ_ST{
private:
  vector<vector<int>> F;
  vector<int> data;
  inline int min(int x, int y){ return x < y ? x : y; }
public:
  RMQ_ST(vector<int> & _data): data(_data){
    int maxJ = (int)(log((double)data.size()) / log(2.0)); // log is based on e, so we need to replace base using logaB = logcB / logca;
    F.resize(data.size(), vector<int>(maxJ, 0));
    int n = data.size();
    for (int i = 0; i < n; i++)
      F[i][0] = data[i];
    for (int j = 1; j <= maxJ; j++){
      for (int i = 0; i < n; i++)
        if (i + (1<<j) < n)
          F[i][j] = min(F[i][j-1], F[i+ (1<<(j-1))][j-1]);
    }
  };
  int answer(int LOW, int HIGH){
    int k = (int)(log((double)HIGH - LOW + 1) / log(2.0));
    return min(F[LOW][k], F[HIGH - (1<<k) + 1][k]);
  }
};


/*
  RMQ can also be used to solve LCA problem. We apply DFS to the target tree, and get Euler sequence. For example:
      1      Depth: 0         The Eular sequence for this tree is 1, 2, 5, 2, 6, 2, 1, 3, 1, 4, 1
    / | \                     The Depth sequence for Eular is     0, 1, 2, 1, 2, 1, 0, 1, 0, 1, 0
    2 3 4    Depth: 1         The first index of each node in Eular sequence is 0, 1, 7, 9, 2, 4 (for example, 3 first appear in Eular
   / \                                        sequence with index 7). Name this sequence with POS
  5   6      Depth: 2         For u and v(POS[u] < POS[v], else swap), LCA(u, v) = RMQ(POS[u], POS[v]). RMQ is built from [0..total].
 */

class RMQ_LCA{
private:
  vector<vector<int>> F;
  vector<int> Depth;
public:
  RMQ_LCA(vector<int> _dep): Depth(_dep){
    int maxJ = (int)(log((double)Depth.size()) / log(2.0));
    F.resize(size, vector<int>(maxJ, 0));
    int n = Depth.size();
    for (int i = 0; i < n; i++)
      F[i][0] = size;
    for (int j = 1; j <= maxJ; j++)
      for (int i = 0; i < n; i++)
        F[i][j] = Depth[F[i][j-1]] < Depth[F[i+ (1<<(j-1))][j-1]] ? F[i][j-1] : F[i+ (1<<(j-1))][j-1]; // here we compare by Depth
  }
  int answer(int LOW, int HIGH){
    int k = (int)(log((double)HIGH - LOW + 1) / log(2.0));
    return Depth[F[LOW][K]] < Depth[F[HIGH - (1<<k)+1][k]] ? F[LOW][k] : F[HIGH - (1<<k) + 1][k]; // but returns index
  }
};

class LCA_RMQ_Based{
private:
  vector<int> Eular; // clear at first
  vector<int> Depth; // clear at first
  vector<int> Pos; // at size n at first, n is the number of nodes
  int size; // initializ to 0
  vector<bool> visited; // initialized to false
  RMQ_LCA r; // initialized after dfs
public:
  void dfs(int u, int cur_depth){
    if (!visited[u]){
      visited[u] = true;
      Pos[u] = size;
    }
    size++;
    Depth.push_back(cur_depth);
    Eular.push_back(u);
    for (int i = 0; i < adj[u].size(); i++){ // use adjacent table
      dfs(adj[u][i], cur_depth + 1);
      Depth.push_back(cur_depth);
      Eular.push_back(u); // after dealing with children, the parent should be added into Eular sequence.
      size++;
    }
  }
  int solve(int u, int v){
    u = Pos[u];
    v = Pos[v];
    return u < v ? r.answer(u, v) : r.answer(v, u);
  }
}


