#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a;
	int b;
	int c;
	int d;

	printf("비밀번호 네자리를 입력하시오");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf((a == 0, b == 9, c == 2, d == 1) ? "해독성공": "해독실패");
}