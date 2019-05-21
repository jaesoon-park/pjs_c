#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//for문 만을 사용해서 1 ~ 9단까지 전부출력하기
	
	int num =0;
	for (int i = 1; i <= 9; i++) {
		
		for (int j = 1; j <= 9; j++) {
			num = i * j;
			printf("%d * %d = %d\n", i, j,num);
		}
		printf("\n");
	}

	//무한 반복하는 사칙연산 프로그램 작성하기

	char op;
	int num1, num2;

	while (1) {
		printf("사칙연산하는 프로그램입니다\n");
		printf("끝내려면 0+0을 입력하세요\n");
		printf("계산하려는 수식(예 : 10 + 20)을 입력하세요");
		scanf("%d %c %d", &num1, &op, &num2);

		if (num1 == 0 && op == '+' && num2 == 0)break;

		switch (op) {
		case'+':
			printf("덧셈 결과는 %d입니다.\n\n", num1 + num2);
			break;
		case'-':
			printf("덧셈 결과는 %d입니다.\n\n", num1 + num2);
			break;
		case'*':
			printf("덧셈 결과는 %d입니다.\n\n", num1 + num2);
			break;
		case'/':
			printf("덧셈 결과는 %d입니다.\n\n", num1 + num2);
			break;
		default:
				printf("다시 입력하세요\n\n");
				break;
		}
	}

	return 0;
}