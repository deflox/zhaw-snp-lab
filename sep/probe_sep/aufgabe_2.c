#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//void reverse(char * const pc);

int main(void) {
    char c[] = "LEO";

    (void) printf("%s\n", c);

    reverse(c);

    (void) printf("%s\n", c);
}

void reverse(char * const pc) {
    size_t length = strlen(pc);
    char save[length + 1];
    strcpy(save, pc);

    for (int i = 1; i <= length; i++) {
        pc[i-1] = save[length - i];
    }
}