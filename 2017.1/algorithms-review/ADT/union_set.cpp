#include <iostream>
#include <vector>
#define MAXN 1000

using namespace std;

int father[MAXN];

int find_re(int x){
  if (father[x] < 0) // use rank to union
    return x;
  father[x] = find_re(father[x]);
  return father[x];
}

int find_loop(int x){
  if (father[x] < 0)
    return x;
  int p = x;
  while (father[p] >= 0)
    p = father[p];
  while (x != p){
    int temp = father[x];
    father[x] = p;
    x = father[x];
  }
  return x;
}

void build_set(int size){
  for (int i = 0; i < size; i++)
    father[i] = -1; // use positve integers to represent father, use negative integers to represent rank
}

void unionSet(int x, int y){
  if ((x = find_re(x)) == (y = find_re(y)))
    return;
  if (father[x] < father[y]){ // since negative interger represents the inverse number of rank, the smaller node represents bigger tree
    father[x] += father[y];
    father[y] = x;
  } else {
    father[y] += father[x];
    father[x] = y;
  }
}

int main(){
  build_set(10);
  cout << find_re(3) << endl;
  cout << find_re(4) << endl;
  unionSet(3, 4);
  unionSet(5, 6);
  unionSet(7, 8);
  unionSet(7, 6); // 5, 6, 7, 8 are a set
  unionSet(0, 1);
  unionSet(0, 2);
  unionSet(0, 4); // 0, 1, 2, 3, 4 are a set
  cout << find_re(0) << " " << find_loop(1) <<
    " " << find_re(2) << " " << find_loop(3) <<
    " " << find_re(4) << endl;
  cout << find_re(7) << " " << find_loop(5) <<
    " " << find_re(6) << " " << find_loop(8) << endl;
  return 0;
}
