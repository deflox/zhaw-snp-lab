#include <stdio.h>
#include <stdlib.h>

int main(void) {

    // gewünschte Ausgabe:
    // Radius =  5 -> Flaeche =   78.56
    // Radius = 10 -> Flaeche =  314.26
    // Radius = 15 -> Flaeche =  707.08
    // Radius = 20 -> Flaeche = 1257.04

    const double pi = 3.1415926535;
    for (int r = 5; r <= 20; r += 5) {
        printf("%7.2f\n", (r*r*pi));
    }
    
    return EXIT_SUCCESS;
    
}