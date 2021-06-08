#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS

int main(void) {
    int v1 = 1;
    printf("%d\n", v1); // prints 1

    char v2 = 'A';
    printf("%d\n", v2); // prints 65
    printf("%c\n", v2); // prints A

    char v3[] = "ABCD";
    printf("%s\n", v3); // prints ABCD

    double v4 = 1.0;
    printf("%f\n", v4); // prints 1.000000
    printf("%.2f\n", v4); // prints 1.00
  
}