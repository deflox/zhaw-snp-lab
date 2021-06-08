#include <stdio.h>

int test(int a[]);

int main() {
    int a[] = {1,2,3}; // code teil liegt im 
    // a++; // a = &a[1];

    int *p = a;
    p++; // p = &a[1];

    int *p = {1,2,3};

    test(a);
}

int test(int x[]) {
    x++;
}