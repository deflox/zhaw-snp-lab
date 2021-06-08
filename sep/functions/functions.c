#include <stdio.h>

void change(int *v);
void change_forbidden(const int *v);

void print_first_arr_element(int *a); // array deklariert als pointer
void print_second_arr_element(int a[]); // array deklariert mit array syntax

int main() {
    int i = 0;
    change(&i);
    (void) printf("%i\n", i); // prints: 5

    // array als parameter
    // ein array ist immer ein pointer und somit immer anpassbar
    // daher sollte parameter mit const deklariert werden wenn nur gelesen wird
    int a[] = {1,2};
    print_first_arr_element(a); // prints: 1
    print_second_arr_element(a); // prints: 2
    // es kann nicht unterschieden werden, ob pointer auf einfache variable zeigt
    // oder auf startposition eines arrays
    int i2 = 3;
    print_first_arr_element(&i2); // ist auch ein valider aufruf
}

void change(int *v) {
    *v = 5;
}
void change_forbidden(const int *v) {
    // *v = 5; // kompilierfehler: ist nicht erlaubt, da const
}

void print_first_arr_element(int *a) {
    printf("%i\n", a[0]);
}
void print_second_arr_element(int a[]) {
    printf("%i\n", a[1]);
}