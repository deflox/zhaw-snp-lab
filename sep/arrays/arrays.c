#include <stdio.h>  // declares printf
#include <stdlib.h> // declares EXIT_SUCCESS

int main(void) {
    int v1[100]; // erzeugt array vom typ integer mit 100 elementen mit undefinierten werten
    int v2[2] = {1,2}; // erzeugt array und intialisiert direkt alle elemente
    int v3[5] = {1,2,3}; // erzeugt array initialisiert nicht alle elemente - der rest wird mit 0 initialisiert
    int v4[] = {1,2,3,4}; // initialisiert array mit implizer arraygroesse

    int v5[3];
    // nicht moeglich, kompilierfehler: v5 = {1,2,3};
    
    const int v6[] = {1,2,3};
    // nicht moeglich kompilierfehler: v6[1] = 5;

    v4[100]; // zugriff auf index > deklariert gibt keinen fehler zur laufzeit!

    // ermitteln der groesse mit sizeof() so moeglich:
    size_t groesse = sizeof(v1)/sizeof(v1[0]); // groesse: 100

    return EXIT_SUCCESS;
}