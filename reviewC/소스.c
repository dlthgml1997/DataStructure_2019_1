
#include <stdio.h>

int main() {

	int *p, q, x;
	p = &q;
	q = 10;
	x = (*p)++;
	printf("%d,%d\n", x, *p); // 11
	return 0;

}