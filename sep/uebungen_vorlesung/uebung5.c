#include <stdio.h>

int main(void) {
	double table[10];
	double *pt, *qt;
	pt = table;
	*pt = 0;
	*(pt + 2) = 3.14;
	pt[5] = 2.5;
	/* Inhalt von table ? */
    // [0,?,3.14,?,?,2.5,?,?,?,?]
    for (int i = 0; i < 10; i++) {
        printf("%f|", table[i]);
    }
    printf("\n");
	
	pt = table + 2;
	qt = pt;
	*qt = 2.718;
	qt[4] = 3.5;
	
	*(table + 8) = 6.7;
	/* Inhalt von table ? */
    // [0,?,2.718,?,?,2.5,3.5,?,6.7,?]
	for (int i = 0; i < 10; i++) {
        printf("%f|", table[i]);
    }
    printf("\n");

	pt = table;
	qt = table + 10;
	printf("%ld\n", qt - pt);
	/* Ausgabe ? */
    // ausgabe ist hier 10, da normale pointer arithmetik über typisierte pointer
    // ein sprung ist immer p+1 -> p + (1*sizeof(double))

	printf("%d\n", (int)qt -(int)pt); // 6.7
	/* Ausgabe ? */
	
	for (; pt < qt; pt++) {
		*pt = 1.23;
	}
	/* Inhalt von table ? */
    // [0,?,2.718,?,3.5,2.5,?,?,6.7,?]
    for (int i = 0; i < 10; i++) {
        printf("%f|", table[i]);
    }
    printf("\n");
}