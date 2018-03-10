#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int BFS(int ** adjMatrix, int N,int *visit,int s)
{
	int *queue = (int*)malloc((N+1)*sizeof(int));

	int front = 0;
	int rear = 0;
	int level = 0;
	int plevel = 0;

	queue[front] = s;
	visit[s] = 1;

	int j, e;
	for (; front <= rear;)
	{
		e = queue[front++];

		for (j = 1; j <= N; ++j)
			if (!visit[j] && adjMatrix[e][j])
			{
				queue[++rear] = j;
				visit[j] = 1;
			}

		if (front == plevel+1)
		{
			if (++level > 6)
				break;
			plevel = rear;
		}
	}

	free(queue);
	return plevel + 1;
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

	for (j = 1; j <= N; ++j)
	{
		for (i = 1; i <= N; ++i)
			visit[i] = 0;

		double f = BFS(adjMatrix, N, visit, j)*100.0 / N;
		
		if (j == 1)
			printf("%d: %.2f%%", j, f);
		else
			printf("\n%d: %.2f%%", j, f);
	}

	return 0;
}