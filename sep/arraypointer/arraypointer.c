#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS

int main(void) {
    int a1[5] = {1,2,3,4,5};
    int *p1;
    p1 = a1; // hier braucht es kein &a1, weil a1 selbst schon ein pointer ist

    int v3 = 1;
    // a1 = &v3; // das ist nicht moeglich, weil pointer nicht veraendert werden kann

    int a2[5] = {5,4,3,2,1};
    if (a1 == a2) printf("Equal\n"); // hier werden die speicheradressen verglichen!

    // pointer arithmetik
    // (p + i) ist das i-te element: p + (i * sizeof(p[0]))
    printf("%i\n", a1[2]); // prints: 3 (generiert: *(a1 + 2))
    printf("%i\n", *(a1 + 2)); // prints: 3
    printf("%i\n", p1[2]); // prints: 3 (generiert: *(p1 + 2))
    printf("%i\n", *(p1 + 2)); // prints: 3

    p1 = (a1 + 2); // identisch zu &a1[2]
    *(p1 + 1) = 2; // identisch zu p1[1] = 2 oder a1[3] = 2
    *(p1 - 1) = 2; // identisch zu p1[-1] = 2 oder a1[1] = 2
    *(p1++) = 2;   // identisch zu p1 = 2; p1++; oder a1[2] = 2; p1 = &p1[1] oder a1[2] = 2; p1 = &a1[4];
    p1 -= 2;       // identisch zu p1 = &p1[-2]; oder p1 = &a1[0]
    //a1++;        // kompilierfehler weil a1 = &a1[1]; nicht erlaubt

    // mehrdimensionale arrays
    // 1D
    int values[10] = {1,2,3};
    int (*pValues) = values; // pointer auf int

    int matrix[10][10] = { {1,2,3}, {1,2,3} };
    int (*pMatrix)[10] = matrix; // pointer auf array aus 10 int

    int board[10][10][10] = { };
    int (*pBoard)[10][10] = board;

    // zugriff ueber pointer arithmetik
    *(*(matrix + 5) + 5) = 5; // gleich wie matrix[5][5] = 5;

    return EXIT_SUCCESS;
}