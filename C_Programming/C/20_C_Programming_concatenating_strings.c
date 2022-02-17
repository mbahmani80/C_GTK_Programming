//concatenating strings in C

#include <stdio.h>
#include <string.h>

int main() {
  char str1[50] = "Hello ";
  char str2[] = "World";

  strcat(str1, str2);

  printf("str1: %s\n", str1);

  return 0;
}
