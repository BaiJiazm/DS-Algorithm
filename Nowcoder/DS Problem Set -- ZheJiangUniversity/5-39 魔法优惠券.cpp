#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Partition(int *n, int low, int high)
{
	int t = n[low];
	int pivotkey = n[low];

	while (low < high)
	{
		while (low < high&&n[high] < pivotkey)
			high--;
		n[low] = n[high];
		while (low < high&&n[low] > pivotkey)
			low++;
		n[high] = n[low];
	}
	n[low] = t;
	return low;
}

void QuickSort(int *n, int low, int high)
{
	int pivotloc = low;
	if (low < high)
	{
		pivotloc = Partition(n, low, high);
		QuickSort(n, low, pivotloc - 1);
		QuickSort(n, pivotloc + 1, high);
	}
}

int main()
{
	int N, M;
	int i;

	scanf("%d", &N);
	int *n = (int*)malloc((N + 1)*sizeof(int));
	for (i = 1; i <= N; ++i)
		scanf("%d", n + i);

	scanf("%d", &M);
	int *m = (int*)malloc((M + 1)*sizeof(int));
	for (i = 1; i <= M; ++i)
		scanf("%d", m + i);

	QuickSort(n, 1, N);
	QuickSort(m, 1, M);

	int value = 0;

	/*for (i = 1; i <= N; ++i)
		printf(" %d", n[i]);
	printf("\n");
	for (i = 1; i <= M; ++i)
		printf("%d ", m[i]);*/

	int a, b;
	for (a = 1, b = 1; a <= N&&b <= M;++a,++b)
		if (n[a] * m[b] > 0)
			value += n[a] * m[b];
		else
			break;

	int a1, b1;
	for (a1 = N, b1 = M; a1 >= a&&b1 >= b; --a1, --b1)
		if (n[a1] * m[b1] > 0)
			value += n[a1] * m[b1];
		else
			break;
	
	printf("%d", value);

	return 0;
}



#include<stdio.h>
#include<stdlib.h>
int compare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}
main()
{
	int N, M, *A, *B, i;
	int sum = 0, a1, a2, b1, b2;
	scanf("%d", &N);
	A = malloc(sizeof(int)*N);
	for (i = 0; i<N; i++)
		scanf("%d", A + i);
	scanf("%d", &M);
	B = malloc(sizeof(int)*M);
	for (i = 0; i<M; i++)
		scanf("%d", B + i);
	qsort(A, N, sizeof(int), compare);
	qsort(B, M, sizeof(int), compare);
	a1 = b1 = 0;
	a2 = N - 1;
	b2 = M - 1;
	while (a1 <= N - 1 && b1 <= M - 1)
	{
		if ((*(A + a1))*(*(B + b1))>0)
		{
			sum = sum + (*(A + a1))*(*(B + b1));
			a1++;
			b1++;
		}
		else
			break;
	}
	while (a2 >= a1&&b2 >= b1)
	{
		if ((*(A + a2))*(*(B + b2))>0)
		{
			sum = sum + (*(A + a2))*(*(B + b2));
			a2--;
			b2--;
		}
		else
			break;
	}
	printf("%d\n", sum);
}
