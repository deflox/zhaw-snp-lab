#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS

int main(void) {
    int v1 = 1;
    printf("size=%zd\n", sizeof(v1)); // prints size=4
    int *v2 = &v1;
    printf("size=%zd\n", sizeof(v2)); // prints size=8
    short v3 = 1;
    printf("size=%zd\n", sizeof(v3)); // prints size=2

    struct s1 { short a; int b,c,d; };
    struct s1 v4 = {1,2,3,4};

    // prints size=12 (weil bei short noch 2 bytes gepadded werden)
    // siehe: https://stackoverflow.com/a/119128
    printf("size=%zd\n", sizeof(v4));

    return EXIT_SUCCESS;
}