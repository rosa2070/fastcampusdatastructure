#include <stdio.h>

int main(void) {
	char a[100];
	gets_s(a, sizeof(a));
	printf("%s\n", a);
	system("pause");
	return 0;
}