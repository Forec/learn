#include <stdio.h>
int y = 1;
int x = 2;

void f();

int main() {
  f();
  printf("y = %x\n", y);
  return 0;
}
