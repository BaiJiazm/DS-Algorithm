#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ShellInsert(int *n, int N, int dk)
{
	int i, j;
	for (i = dk + 1; i <= N; ++i)
		if (n[i] < n[i - dk])
		{
			n[0] = n[i];
			for (j = i - dk; j > 0 && n[0] < n[j]; j -= dk)
				n[j + dk] = n[j];
			n[j + dk] = n[0];
		}
}

void ShellSort(int *n, int N)
{
	int dlta[] = { 320,160,80, 40,20,10,5,3,1 };
	int k = sizeof(dlta) / sizeof(int);

	int i;
	for (i = 0; i < k; ++i)
		ShellInsert(n, N, dlta[i]);
}


void OutPut(int *n, int N)
{
	int *p = n + 1;
	int *q = n + N;

	if (p <= q)
		printf("%d", *p++);

	for (; p <= q;)
		printf(" %d", *p++);
}
int main()
{
	int N;
	scanf("%d", &N);

	int *n = (int *)malloc((N + 1)*sizeof(int));

	int i;
	for (i = 1; i <= N; ++i)
		scanf("%d", n + i);

	ShellSort(n, N);
	OutPut(n, N);

	return 0;
}