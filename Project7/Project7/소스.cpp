#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int y;
	int sum;
	int num1, num2, num3, num4;
	
	printf("�� ������ �Է��ϼ��� : ");
	scanf("%d %d", &x, &y);
	sum = x + y;
	num1 = x - y;
	num2 = x * y;
	num3 = x % y;
	num4 = x / y;
	printf("%d %d %d %d %d", sum, num1, num2, num3, num4);
}