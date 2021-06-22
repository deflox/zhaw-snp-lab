#include <stdio.h>

int main(void) {
	
	int *ap, *bp;
	int c = 5, d;
	
	ap = &c;        //  ap = 0x1  *ap = 5
	printf("ap=%d, *ap=%d\n", ap, *ap);
	c++;            //   c = 6    *ap = 6
	printf("c=%d, *ap=%d\n", c, *ap);
	*ap = -10;      //   c = -10  *ap = -10
	printf("c=%d, *ap=%d\n", c, *ap);
	bp = &c;
	c = 15;         // *ap = 15  *bp = 15
	printf("*ap=%d, *bp=%d\n", *ap, *bp);
	*bp = *ap / 2;  //   c = 7
	printf("c=%d\n", c);
	ap = &d;        //  ap = 0x2 *bp = 7
	printf("ap=%d, *bp=%d\n", ap, *bp);
	d = 3;          // *ap = 3   *bp = 7
	printf("*ap=%d, *bp=%d\n", *ap, *bp);

}