#include <stdio.h>
#include <stdlib.h>

extern int multiply(int n1, int n2);  // multiply function was defined in assembly code 

int main(int argc, char *argv[]) {
  int n1 = atoi(argv[1]);   // integer from string representation 
  int n2 = atoi(argv[2]);

  int result = multiply(n1, n2);

  printf("%d\n", result);

  return 0;
}