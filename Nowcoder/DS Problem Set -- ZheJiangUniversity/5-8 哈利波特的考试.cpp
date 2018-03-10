#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max_Int 2147483647

int latestPath(int **adjMatrix, int N,  int *distance, int start)
{
	int *visit = (int *)malloc((N+1)*sizeof(int));

	int i, j;
	for (i = 1; i <= N; ++i)
	{
		visit[i] = 0;
		distance[i] = adjMatrix[start][i];
	}

	visit[start] = 1;
	distance[start] = 0;

	int now;
	int w;

	for (i = 1; i < N; ++i)
	{
		for (j = 1, w = Max_Int; j <= N; ++j)
			if (!visit[j] && distance[j] < w)
			{
				w = distance[j];
				now = j;
			}

		visit[now] = 1;

		for (j = 1; j <= N; ++j)
		{
			if (!visit[j] && adjMatrix[now][j] != Max_Int)
				if (w + adjMatrix[now][j] < distance[j])
					distance[j] = w + adjMatrix[now][j];
		}
	}

	free(visit);
	return w;
}

int main()
{
	int N;
	int M;
	scanf("%d%d", &N, &M);

	int **adjMatrix = (int **)malloc((N + 1)*sizeof(int *));
	int *distance = (int *)malloc((N + 1)*sizeof(int));

	int i, j;
	for (i = 1; i <= N; ++i)
	{
		adjMatrix[i] = (int *)malloc((N + 1) *sizeof(int));

		for (j = 1; j <= N; ++j)
		{
			adjMatrix[i][j] = Max_Int;
		}
	}

	int v1, v2, w;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &w);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
	}

	for (i = 1, v1 = Max_Int, v2 = v1; i <= N; ++i)
	{
		v1 = latestPath(adjMatrix, N, distance, i);
		if (v1 == Max_Int)
		{
			printf("0");
			return 0;
		}
		if (v2 > v1)
		{
			j = i;
			v2 = v1;
		}
	}

	if (v2 != Max_Int)
	{
		printf("%d %d", j, v2);
	}

	return 0;
}