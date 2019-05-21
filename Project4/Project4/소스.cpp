#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/*
	//2단계
	int a = 0;
	int b = 0;

	printf("직사각형 별찍기\n");
	printf("가로 길이와 세로길이를 제시해 주세요 >>");
	scanf("%d %d", &a, &b);

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			printf("*");
		}
		printf("\n");
	}
	*/
	
	/*
	//1단계
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			printf("*");
		}
		printf("\n");
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= 4 - i; j++){
			printf(" ");
		}
		for(j = 0; j<= i; j++){
			printf("*");
		}
		printf("\n");
	}

	for (int i = 4; i >= 0; i--) {
		for (int j = 0; j <= 4 - i; j++){
			printf(" ");
		}
		for(j = 0; j<= i; j++){
			printf("*");
		}
		printf("\n");
	}
	
	//2단계 피라미드찍기
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j <= 4 - i; j++){
			printf(" ");
		}
		for(int j = 0; j< i * 2 +1; j++){
			printf("*");
		}
		printf("\n");
	}
	
     */
	
	//3단계 별찍기
		for(int i = 0; i < 3;i++){
			for(int j = 0; j<10+i; j++){
				if(j < 9 -i)
				printf(" ");
				else
				printf("*");
		
			}
			printf("\n");
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 19 - i; j++) {
				if (j < i)
				printf(" ");
				else 
				printf("*");
				}
			printf("\n");
			}
		
		for(int i = 3; i>0;i--){
			for(int j =0; j<19-i+1;j++){
				if(j < i-1)
				printf(" ");
				else
				printf("*");				
					}
			printf("\n");
			}
		for(int i = 2; i>=0;i--){
			for(int j =0; j<10+i;j++){
				if(j < 9 -i)
				printf(" ");
				else
				printf("*");
				}
				printf("\n");
			}



	
}