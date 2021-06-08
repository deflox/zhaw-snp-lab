#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS

int main(void) {
    int v1 = 1; // variable vom typ int
    int* p1;    // pointer welcher auf ein objekt vom typ int zeigt
    //int *p1;    // alternative deklarationsmoeglichkeit
    p1 = &v1;   // hole adresse von der variable v1 und setze sie in p1
    *p1 = 2;    // hole objekt hinter pointer p1 und setze wert 2

    int *v2[20];   // array fuer 20 pointer auf objekt vom typ int
    int (*p2)[20]; // pointer auf ein array mit 20 int elementen

    int **ppi; // ein pointer auf einen pointer welcher auf ein objekt vom typ int zeigt

    int *p3, v3; // erzeugt int-pointer p aber normale int variable q

    // void pointer
    int v4 = 5;
    int *p4 = &v4;
    void *p5 = p4; // erzeuge void pointer - irgendeine speicheradresse kann zugewiesen werden
    int *p6 = p5;  // dieser pointer kann auch an andere pointer zugewiesen werden

    // structs
    struct Point { int x,y,z; };
    struct Point point = {1,2,3};
    struct Point *pPoint = &point;
    printf("%i\n", pPoint->x); // prints: 1

    return EXIT_SUCCESS;
}