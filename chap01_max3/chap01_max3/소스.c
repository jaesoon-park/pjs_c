#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a, b, c;
	int max;
	printf("�� ������ �ִ��� ���մϴ�\n");
	printf("a�� �� : ");
	scanf("%d", &a);
	printf("b�� �� : ");
	scanf("%d", &b);
	printf("c�� �� : ");
	scanf("%d", &c);

	max = a;
	if (b > max) {
		max = b;
	}
	if (c > max) {
		max = c;
	}

	printf("�ִ��� %d �Դϴ�.\n", max);

}