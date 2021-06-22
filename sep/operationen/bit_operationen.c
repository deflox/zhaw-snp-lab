#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void printBits(u_int16_t n);

int main() {
    u_int16_t n = 1u << 13 | 1u << 3;

    printf("%i\n", n);
    (void) printBits(n);

    return EXIT_SUCCESS;
}

void printBits(u_int16_t n) {

    int bits = 16; // change depending on the datatype
    u_int16_t mask = 1u << bits - 1;

    for (int i = 0; i < bits; i+=1) {
        if ((n & mask) == mask) {
            printf("1");
        } else {
            printf("0");
        }

        // shift mask 1 to the right
        mask >>= 1;
    }

    printf("\n");
}