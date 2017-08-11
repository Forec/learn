# 1 "sum.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "sum.c"
int sum(int * a, int n) {
  int i, s = 0;
  for (i = 0; i < n; i++) {
    s += a[i];
  }
  return s;
}
