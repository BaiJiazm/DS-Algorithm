#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct arcNode
{
	int node;
	int arc;
	struct arcNode *nextArc;
};

struct adjListNode {
	int node;
	arcNode* fistarc;
};

int TopoLogicalOrder(int **adjMatrix, int N, int *ve, int *S)
{
	int *stack0 = (int *)malloc((N + 1)*sizeof(int));
	int Stop = 0;
	int stop = 0;
    
	int i;
	for (i = 1; i <= N; ++i)
	{
		if (adjMatrix[i][0] == 0)
			stack0[stop++] = i;
		ve[i] = 0;
	}

	int e;
	while (stop)
	{
		e = stack0[--stop];
		S[Stop++] = e;
		for (i = 1; i <= N; ++i)
			if (adjMatrix[e][i])
			{
				if (--adjMatrix[i][0] == 0)
					stack0[stop++] = i;
				if (ve[e] + adjMatrix[e][i] > ve[i])
					ve[i] = ve[e] + adjMatrix[e][i];
			}
	}

	free(stack0);

	if (Stop < N)
		return 0;
	else
		return 1;
}


int criticalPath(int **adjMatrix, int N,struct adjListNode* adjList)
{
	int *ve = (int *)malloc((N + 1)*sizeof(int));
	int *vl = (int *)malloc((N + 1)*sizeof(int));
	int *S = (int *)malloc((N + 1)*sizeof(int));

	if (TopoLogicalOrder(adjMatrix, N, ve, S) == 0)
		return 0;

	int i, j;
	for (i = 1; i <= N; ++i)
		vl[i] = ve[N];

	int Stop = N;
	int e;

	while (Stop)
	{
		e = S[--Stop];
		for (i = 1; i <= N; ++i)
			if (adjMatrix[e][i])
				if (vl[e] > vl[i] - adjMatrix[e][i])
					vl[e] = vl[i] - adjMatrix[e][i];
	}

	printf("%d\n", ve[N]);

	/*for (i = 1; i <= N; ++i)
		if (ve[i] == vl[i])
			printf("%d ", i);*/

	/*for (i = 0; i != N - 1;)
		for (j = i + 1;; ++j)
			if (ve[S[j]] == vl[S[j]])
			{
				printf("%d->%d\n", S[i], S[j]);
				i = j;
				break;
			}*/

	/*for (i = S[0]; i != S[N - 1];)
		for (j = 1; j <= N;++j)
			if (adjMatrix[i][j] && ve[j] == vl[j])
			{
				printf("%d->%d\n", i, j);
				i = j;
				break;
			}*/

	struct arcNode*p;
	for (i = 1; i <= N; i++)
		if (ve[i]==vl[i])
			for (p = adjList[i].fistarc; p; p = p->nextArc)
			{
				j = p->node;
				if (ve[j] == vl[j] && vl[j] - vl[i] == p->arc)
					printf("%d->%d\n", i, j);
			}

	return 1;
}

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int **adjMatrix = (int **)malloc((N + 1)*sizeof(int *));
	struct adjListNode* adjList = (struct adjListNode *)malloc((N + 1)*sizeof(struct adjListNode));

	int i, j;
	for (i = 1; i <= N; ++i)
	{
		adjMatrix[i] = (int *)malloc((N + 1)*sizeof(int));
		for (j = 0; j <= N; ++j)
			adjMatrix[i][j] = 0;
		adjList[i].fistarc = NULL;
	}

	int v1, v2, w;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &w);
		adjMatrix[v1][v2] = w;
		adjMatrix[v2][0] ++;
		struct arcNode *p = (struct arcNode*)malloc(sizeof(struct arcNode));
		p->node = v2;
		p->arc = w;
		p->nextArc = adjList[v1].fistarc;
		adjList[v1].fistarc = p;
	}

	if (criticalPath(adjMatrix, N,adjList) == 0)
		printf("0");

	return 0;
}
