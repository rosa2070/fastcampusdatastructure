#include <stdio.h>

int main(void) {
	int a[5] = {1,2,3,4,5};
	int *p = a;
	printf("%d\n", *(p++));
	printf("%d\n", *(++p));	
	printf("%d\n", *(p+2));	
	return 0;
}
