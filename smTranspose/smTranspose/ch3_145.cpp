#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct {
	int row;
	int col;
	int value;
}term;

void smTranspose(term a[], term b[]) {
	int m, n, v, p;
	m = a[0].row;
	n = a[0].col;
	v = a[0].value;

	b[0].row = n;
	b[0].col = m;
	b[0].value = v;

	if (v > 0) {
		p = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= v; j++) {
				if (a[j].col = i) {
					b[p].row = a[j].col;
					b[p].col = a[j].row;
					b[p].value = a[j].value;
					p++;
				}
			}
		}
	}
}

void main()
{
	term a[11] = {8,7,10,
	0,2,2};
	term b[11];

	for (int i = 0; i < b[10].value; i++)
	{
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	}
	

	smTranspose(a, b);
}
