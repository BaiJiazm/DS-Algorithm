#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int BFS(int **adjMatrix, int N, int *visit, int s)
{
	int *queue = (int *)malloc((N + 1)*sizeof(int));

	int totalDistance = 0;
	int front = 0;
	int rear = 0;
	int distance = 1;
	int pLast = rear;

	queue[front] = s;
	visit[s] = 1;

	int i, e;
	for (; front <= rear;)
	{
		e = queue[front++];

		for (i = 1; i <= N;++i)
			if (!visit[i] && adjMatrix[e][i])
			{
				queue[++rear] = i;
				visit[i] = 1;
				totalDistance += distance;
			}

		if (front == pLast + 1)
		{
			pLast = rear;
			distance++;
		}
	}

	free(queue);
	if (front < N)
		return -1;
	return totalDistance;
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
			adjMatrix[i][j] = 0;
	}

	int v1, v2;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d", &v1, &v2);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = 1;
	}

	int *visit = (int *)malloc((N + 1)*sizeof(int));
	
	int CN;
	scanf("%d", &CN);

	int *CNS = (int *)malloc((CN+1)*sizeof(int));
	double *result = (double *)malloc((CN+1)*sizeof(double));
	
	for (i = 1; i <= CN; ++i)
	{
		scanf("%d", CNS + i);

		for (j = 1; j <= N; ++j)
			visit[j] = 0;

		int r = BFS(adjMatrix, N, visit, CNS[i]);
		result[i] = r == -1 ? 0.0 : (N - 1.0) / r;
	}

	for (i = 1; i <= CN; ++i)
		printf("Cc(%d)=%.2f\n", CNS[i], result[i]);

	return 0;
}