#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int find_second_last_number(int i);

void find_schaltjkahr(int jahr);

int main(void) {
    (void) printf("%i", find_second_last_number(563));
}

int find_second_last_number(int i) {
    return ((i - (i%10)) / 10 ) % 10;
}

void find_schaltjahr(int jahr) {
    if ((jahr%4) == 0) {
        

    } else {
        (void) printf("NO");
    }
}