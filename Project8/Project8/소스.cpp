#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//for�� ���� ����ؼ� 1 ~ 9�ܱ��� ��������ϱ�
	
	int num =0;
	for (int i = 1; i <= 9; i++) {
		
		for (int j = 1; j <= 9; j++) {
			num = i * j;
			printf("%d * %d = %d\n", i, j,num);
		}
		printf("\n");
	}

	//���� �ݺ��ϴ� ��Ģ���� ���α׷� �ۼ��ϱ�

	char op;
	int num1, num2;

	while (1) {
		printf("��Ģ�����ϴ� ���α׷��Դϴ�\n");
		printf("�������� 0+0�� �Է��ϼ���\n");
		printf("����Ϸ��� ����(�� : 10 + 20)�� �Է��ϼ���");
		scanf("%d %c %d", &num1, &op, &num2);

		if (num1 == 0 && op == '+' && num2 == 0)break;

		switch (op) {
		case'+':
			printf("���� ����� %d�Դϴ�.\n\n", num1 + num2);
			break;
		case'-':
			printf("���� ����� %d�Դϴ�.\n\n", num1 + num2);
			break;
		case'*':
			printf("���� ����� %d�Դϴ�.\n\n", num1 + num2);
			break;
		case'/':
			printf("���� ����� %d�Դϴ�.\n\n", num1 + num2);
			break;
		default:
				printf("�ٽ� �Է��ϼ���\n\n");
				break;
		}
	}

	return 0;
}