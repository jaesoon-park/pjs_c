#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{

	//1조문제
	/*무게의 단위인 킬로그램(kg)을 소수로 입력 받아 온스(oz)로 
	계산하여 출력하는 프로그램을 작성하시오
	1온스(oz)는 0.02835킬로그램(kg)*/
	//2조문제
	/*정수인 천만 이하의 한 수를 입력받아 우리가 사용하는 단위인
	만,천,백,십,일 단위로 출력하는 프로그램을 작성하시오
	ex)8512694 - > 851만 2천 6백 9십 4*/
	//3조문제
	/*표준입력으로 정수하나를 입력하여 짝수이면 "수박"  홀수이면 "박수"
	가 나오도록 출력하는 프로그램을 작성하시오
	ex) 5 >> 박수*/
	//4조문제
	/*천만 이하의 초(second)단위의 한 수를 입력하여 그 수를 (minute) (second)
	 로 바꾸어 주는 프로그램을 작성하시오 
	 ex)  1000초 >> 16분 40초 입니다.*/
	//5조문제
	/*삼차원공간에서 다음 세 점 (3.2,4.6,1.2)와(-2.1,-5.9,9.5)그리고 
	(6.4,3.8,6.5)의 중간지점을 출력하는 프로그램 작성*/
	//6조문제
	/*조건연산자를 이용하여 임의의 달을 입력 받아 이 달이 상반기이면 
	"상반기입니다."를 하반기이면 "하반기입니다."를 출력하는 프로그램을 작성하시오*/

	//1조
	/*
	double kg = 0;
	double oz;
	
	printf("당신의 몸무게는 ? >>");
	scanf("%lf",&kg);
	oz = kg / 0.02835;
	printf("%.2fkg은 %f oz입니다",kg,oz);
	*/

	//2조
	/*
	int x;
	int a,b,c,d,e;
	
	printf("천만이하의 자연수를 입력하세요 >>");
	scanf("%d",&x);
	a = x / 10000;
	b = x / 1000;
	b = b % 10;
	c = x / 100;
	c = c % 10;
	d = x / 10;
	d = d % 10;
	e = x % 10;
	printf("%d >> %d만 %d천 %d백 %d십 %d", x, a, b, c, d, e);
	*/
	//3조
	
	/*int x;
	
	printf("정수를 하나 입력하세요 >>");
	scanf("%d",&x);
	printf("%s",(x % 2 == 0) ? "수박" : "박수");
	*/
	
	//4조
	/*
	int input;
	int minute;
	int second;
	int x = 60;
	printf("초단위로 한 수를 입력하세요 >>");
	scanf("%d",&input);

	minute = input / x; 
	second = input % x;

	printf("%d초 >> %d분 %d초입니다",input,minute,second);
	*/
	//5조
	/*
	double x1,x2,x3;
	double y1,y2,y3;
	double z1, z2, z3;
	x1 = 3.2, x2 = -2.1, x3 = 6.4;
	y1 = 4.6, y2 = -5.9, y3 = 3.8;
	z1 = 1.2, z2 = 9.5, z3 = 6.5;

	printf("%f %f %f", (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3, (z1 + z2 + z3) / 3);
	*/
	//6조
	/*
	int month;
	
	printf("지금은 몇월입니까? >>");
	scanf("%d",&month);
	printf("%d월은\n",month);
	printf("%s", (month <= 6 && month >= 1) ? "상반기입니다" : (month >= 7 && month <= 12) ? "하반기입니다" : "잘못입력하셨습니다.");
	*/
	

}