#include <stdio.h>
#include <stdlib.h>

int main() {
    // malloc
    int *p = malloc(3 * sizeof(int));
    if (p == NULL) return EXIT_FAILURE;

    p[0] = 1;
    *(p + 1) = 2;
    p[2] = 3;

    // free the memory from the heap
    free(p);

    p = calloc(3, sizeof(int));
    if (p == NULL) return EXIT_FAILURE;

    p[0] = 1;
    *(p + 1) = 2;
    p[2] = 3;

    // free the memory from the heap
    free(p);

    return EXIT_SUCCESS;
}