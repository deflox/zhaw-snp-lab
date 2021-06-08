#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS
#include <string.h> // strlen, strcmp, strcpy, strcat

int main(void) {
    // initialisierung
    char v1[] = "test1"; // char array: [t][e][s][t][1][\0]
    // initialisierung im Nachhinein nicht moeglich, kompilierfehler: v1 = "test";

    char v2[5] = "test2"; // char array: [t][e][s][t][2] -> ist kein String!
    char v3[6] = "test3"; // char array: [t][e][s][t][3][\0]
    char v4[7] = "test4"; // char array: [t][e][s][t][4][\0][\0]
    char v5[6]; v5[0] = 't'; v5[1] = 'e'; v5[2] = 's'; v5[3] = 't'; v5[4] = '5'; v5[5] = '\0';
    char *v6 = "test6";  // pointer der auf char array zeigt: [t][e][s][t][\0], funktioniert nur mit Strings!!
    v6[0] = 'a'; // fuehrt zu segmentation fault da inhalt im code-segment liegt

    printf("%s\n", v1); // prints: test1
    printf("%s\n", v2); // prints: test2test1 (da nicht mit \0 terminiert wird einfach im Speicher weitergelesen)

    // strlen
    // gibt die laenge von strings bis \0 aus
    printf("%zu\n", strlen(v1)); // prints: 5

    // strcmp
    // vergleicht strings und gibt 0 zurueck falls identisch
    char v7[] = "test1";
    printf("%i\n", strcmp(v1, v7)); // prints: 0
    printf("%i\n", strcmp(v1, v2)); // prints: -1

    // strcpy
    // kopiere string von source nach destination - destination muss genug gross sein!
    char v8[6];
    strcpy(v8, v1);
    printf("%s\n", v8);

    // strcat
    // fuege string ans ende eines anderen strings an
    char v9[11] = "test9"; // char array: [t][e][s][t][2][\0][\0][\0][\0][\0][\0]
    printf("%s\n", v9); // prints: test9
    strcat(v9, v1); // char array: [t][e][s][t][2][t][e][s][t][1][\0]
    printf("%s\n", v9); // prints: test9test1

    return EXIT_SUCCESS;
}