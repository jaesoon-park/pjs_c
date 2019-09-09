#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b, c;
	int max;
	printf("세 정수의 최댓값을 구합니다\n");
	printf("a의 값 : ");
	scanf("%d", &a);
	printf("b의 값 : ");
	scanf("%d", &b);
	printf("c의 값 : ");
	scanf("%d", &c);

	max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}

	printf("최댓값은 %d 입니다.\n", max);

	return 0;
}