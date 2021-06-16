#include <stdio.h> 

int main(void) {
	char a[20] = "Dongbin Na";
	char b[20] = "Hojoon Seok";
	printf("두 배열의 사전 순 비교: %d\n", strcmp(a, b));
	system("pause");
	return 0;
}