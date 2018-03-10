#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max_Int 2147483647

int MST(int **adjMatrix, int N)
{
	int *tem = (int *)malloc((N + 1)*sizeof(int));

	int value = 0;
	int sVertex = 1;

	int i, j, k;
	for (i = 1; i <= N; ++i)
	{
		tem[i] = adjMatrix[1][i];
	}

	tem[1] = 0;

	for (i = 1; i < N; ++i)
	{
		for (j = 1,k=Max_Int; j <= N; ++j)
			if (tem[j] != 0 && tem[j] < k)
			{
				sVertex = j;
				k = tem[j];
			}
	    
		if (k == Max_Int)
			return -1;

		tem[sVertex] = 0;
		value += k;

		for (j = 1; j <= N; ++j)
			if (tem[j] != 0 && tem[j] > adjMatrix[sVertex][j])
				tem[j] = adjMatrix[sVertex][j];
	}

	return value;
}

int main()
{
	int N;
	int M;

	scanf("%d%d", &N, &M);

	int **adjMatrix = (int **)malloc((N + 1)*sizeof(int *));

	int i, j;
	for (i = 1; i <= N; ++i)
	{
		adjMatrix[i] = (int *)malloc((N + 1)*sizeof(int));
		for (j = 1; j <= N; ++j)
			adjMatrix[i][j] = Max_Int;
	}

	int v1, v2, w;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &w);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
	}

	printf("%d", MST(adjMatrix, N));

	return 0;
}