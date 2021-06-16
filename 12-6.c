#include <stdio.h>

int main(void) {
	char a[20] = "I like you";
	char b[20] = "like";
	printf("찾은 문자열: %s\n", strstr(a, b));
	system("pause");
	return 0;
}