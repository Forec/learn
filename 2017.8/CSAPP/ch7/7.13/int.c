#include <stdio.h>
#include <malloc.h>

int main() {
  int *p = malloc(32);
  printf("=============\n");
  free(p);
  return 0;
}
