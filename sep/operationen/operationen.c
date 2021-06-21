#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main() {
    u_int16_t n = 2^16;
    n = 1u << 13 | 1u << 3;

    printf("%i\n", n);
    
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    
    printf("\n");

    return EXIT_SUCCESS;
}