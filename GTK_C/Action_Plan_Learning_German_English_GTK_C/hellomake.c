// hellomake.c
// gcc -o hellomake hellomake.c hellofunc.c -I.
#include <hellomake.h>

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
