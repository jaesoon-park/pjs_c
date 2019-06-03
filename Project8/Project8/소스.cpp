#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int i = 1;
	
	
	while(i < 10){
		
		int x = 1;
		do {
			
			printf("%d * %d = %d\n", i, x, i *x);
			x++;
		} while (x < 10);
		
		i++;
		printf("\n");
		
	}
}