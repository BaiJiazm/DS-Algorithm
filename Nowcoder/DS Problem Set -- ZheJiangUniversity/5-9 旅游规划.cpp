#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max_Int 2147483647

void latestPath(int **adjMatrix,int **adjMatrixCost, int N, int **path, int *cost, int *distance, int start, int end)
{
	int *visit = (int *)malloc(N*sizeof(int));

	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			path[i][j] = 0;

		visit[i] = 0;
		cost[i] = 0;

		distance[i] = adjMatrix[start][i];

		if (distance[i] < Max_Int)
		{
			path[i][start] = 1;
			path[i][i] = 1;
			cost[i] = adjMatrixCost[start][i];
		}
	}

	path[start][start] = 1;
	visit[start] = 1;
	distance[start] = 0;

	int now, k;
	int w;

	for (i = 1; i < N; ++i)
	{
		for (j = 0, w = Max_Int; j < N; ++j)
			if (!visit[j] && distance[j] < w)
			{
				w = distance[j];
				now = j;
			}

		visit[now] = 1;

		if (now == end)
			return;

		for (j = 0; j < N; ++j)
		{
			if (!visit[j] && adjMatrix[now][j] != Max_Int)
				if (w + adjMatrix[now][j] < distance[j])
				{
					distance[j] = w + adjMatrix[now][j];

					for (k = 0; k < N; ++k)
						path[j][k] = path[now][k];
					path[j][j] = 1;

					cost[j] = cost[now] + adjMatrixCost[now][j];
				}
				else if (w + adjMatrix[now][j] == distance[j] && cost[j]>cost[now] + adjMatrixCost[now][j])
				{
					for (k = 0; k < N; ++k)
						path[j][k] = path[now][k];
					path[j][j] = 1;

					cost[j] = cost[now] + adjMatrixCost[now][j];
				}
		}
	}
}

int main()
{
	int N;
	int M;
	scanf("%d%d", &N, &M);

	int start, end;
	scanf("%d%d", &start, &end);

	int **adjMatrix = (int **)malloc(N*sizeof(int *));
	int **adjMatrixCost = (int **)malloc(N*sizeof(int *));
	int **path = (int **)malloc(N*sizeof(int *));
	int *distance = (int *)malloc(N*sizeof(int));
	int *cost = (int *)malloc(N*sizeof(int));

	int i, j;
	for (i = 0; i < N; ++i)
	{
		adjMatrix[i] = (int *)malloc(N *sizeof(int));
		adjMatrixCost[i] = (int *)malloc(N *sizeof(int));

		path[i] = (int *)malloc(N *sizeof(int));
		for (j = 0; j < N; ++j)
		{
			adjMatrix[i][j] = Max_Int;
			path[i][j] = 0;
		}
	}

	int v1, v2, w, c;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d%d%d", &v1, &v2, &w, &c);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
		adjMatrixCost[v1][v2] = adjMatrixCost[v2][v1] = c;
	}

	latestPath(adjMatrix, adjMatrixCost, N, path, cost, distance, start, end);

	printf("%d %d", distance[end], cost[end]);

	return 0;
}