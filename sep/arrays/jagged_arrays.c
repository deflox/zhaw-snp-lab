#include <stdio.h>

int main() {
    char days[7][10] = {"Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday", "Sunday"};
    char *pdays[7]   = {"Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday", "Sunday"}; 

    (void) printf("%zd %zd\n", sizeof(days), sizeof(pdays));
    (void) printf("%zd %zd\n", sizeof(days + 1), sizeof(pdays + 1));
    (void) printf("%zd %zd\n", sizeof(days[1]), sizeof(pdays[1]));

    (void) printf("%s %s\n", days[4], pdays[4]);
    (void) printf("%zd\n", days[4] -days[1]);
    (void) printf("%zd\n", pdays[4] -pdays[1]);
    (void) printf("%zd\n", &days[2][3] -&days[0][0]);
    (void) printf("%zd\n", &pdays[2][3] -&pdays[0][0]);
}