#include <stdio.h>
#include <string.h>

char a[4]  = "Maus";
char b[]   = "Hund";
char c[14] = "Katze";
char d     = 'x';

int main(void) {
	printf("strlen(a)=%ld\n", strlen(a)); /* Ausgabe? 8 */
	printf("strlen(b)=%ld\n", strlen(b)); /* Ausgabe? 4 */
	printf("strlen(c)=%ld\n", strlen(c)); /* Ausgabe? 5 */
	
	strcat(c, b);
	printf("%s\n", c);  /* Ausgabe? KatzeHund */
	strcat(c, a);
	printf("%s\n", c);  /* Ausgabe? KatzeHundMausHund */
	printf("%c\n", d);  /* Ausgabe? u (ist hier u weil der Speicherinhalt überschrieben wurde) */
}