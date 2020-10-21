#include <stdio.h>

char *echo() {
  char buffer[32];
  return gets(buffer);
}

int level1() {
  printf("Made it to level 1\n");
}

int level2(int x) {
  if (x == 0xff)
    printf("Made it to level 2 with x = %#x\n", x);
  else
    printf("Made it to level 2 but x is %#x or %d\n", x, x);
}

int junk(int x) {
  return x & 0x101;
}

int helper() {
  printf("You make it to helper\n");
  char buffer[8];
  gets(buffer);
  junk(0xff);
}
 
int main() {
  printf("Type something\n");
  printf("You typed %s\n", echo());
}
