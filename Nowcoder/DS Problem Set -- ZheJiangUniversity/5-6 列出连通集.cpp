#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


void DFS(int **adjMatrix, int N, int *visit,int k)
{
	visit[k] = 1;
	printf(" %d", k);

	int i;
	for (i = 0; i < N; ++i)
		if (!visit[i] && adjMatrix[k][i])
			DFS(adjMatrix, N, visit, i);
}

void DFSConection(int ** adjMatrix,int N)
{
	int *visit = (int *)malloc(N*sizeof(int));

	int i;
	for (i = 0; i < N; ++i)
		visit[i] = 0;

	for (i = 0; i < N; ++i)
	{
		if (!visit[i])
		{
			printf("{");
			DFS(adjMatrix, N, visit, i);
			printf(" }\n");
		}
	}
}

void BFSConection(int ** adjMatrix, int N)
{
	int *visit = (int *)malloc(N*sizeof(int));
	int *queue = (int*)malloc(N*sizeof(int));
	int first, end;

	int i, j, e;
	for (i = 0; i < N; ++i)
		visit[i] = 0;

	for (i = 0; i < N; ++i)
	{
		if (!visit[i])
		{
			first = 0;
			end = 0;
			queue[first] = i;
			visit[i] = 1;

			printf("{");

			while (first <= end)
			{
				e = queue[first++];
				printf(" %d", e);

				for (j = 0; j < N; ++j)
					if (!visit[j] && adjMatrix[e][j])
					{
						queue[++end] = j;
						visit[j] = 1;//���׳��������ǽ����м�����visit ������ڳ����д�ӡʱ������visit�����п��ܻ��ظ�����
					}
			}

			printf(" }\n");
		}
	}
}

int main()
{
	int N;
	int M;

	scanf("%d%d", &N, &M);
	
	int **adjMatrix = (int **)malloc(N*sizeof(int *));

	int i, j;
	for (i = 0; i < N; ++i)
	{
		adjMatrix[i] = (int *)malloc(N*sizeof(int));
		for (j = 0; j < N; ++j)
			adjMatrix[i][j] = 0;
	}

	int v1, v2;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d", &v1, &v2);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = 1;
	}

	DFSConection(adjMatrix, N);

	BFSConection(adjMatrix, N);


	return 0;
}