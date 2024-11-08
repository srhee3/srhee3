#include <stdio.h>
#include <stdlib.h> 

extern int fibonacci(int n);   // fibonacci is defined in our assembly code so we use extern to redefine it 

int main(int argc, char **argv) {

    int n = atoi(argv[1]);
    int result = fibonacci(n);

    printf("%d\n", result);

    return 0;
}

// C code is same for both fibonacci programs 