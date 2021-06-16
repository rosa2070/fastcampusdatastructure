#include <stdio.h>

int main(void) {
	char a[30] = "My name is ";
	char b[20] = "Dongbin Na";
	strcat(a, b);
	printf("%s\n", a);
	system("pause");
	return 0;
}