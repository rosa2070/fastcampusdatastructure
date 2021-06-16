#include <stdio.h>

int main(void) {
	char a[20] = "My name";
	char b[20] = "Dongbin Na";
	strcpy(a, b);
	printf("%s", a);
	system("pause");
	return 0;
}