int main(void) {

	double x, y = 3.0;      /* x = ? y = 3.0 */
	int i, j = 4;           /* i = ? j = 4 */
	i = 2.5 + y;            /* i = 5 */
	x = 5 * i / 3;          /* x = 8.0 */
	x = 5.0 * i / 3;        /* x = 8.33 */
	i += j;                 /* i = 9 */
	i = ++j;                /* i = 5 j = 5 */
	i = j++;                /* i = 5 j = 6 */
	x = 3 + (y = i + 5.0);  /* x =  y = */

}