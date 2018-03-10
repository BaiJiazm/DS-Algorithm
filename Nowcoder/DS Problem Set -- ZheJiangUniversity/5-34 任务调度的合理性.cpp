#include <stdio.h>
#include <stdlib.h>

struct arcNode
{
	int node;
//	int arcLen;
	struct arcNode *nextArc;
};

struct adjListNode {
	struct arcNode*firstArc;
	int inDegree;
};

int TopoSort(struct adjListNode *adjList, int N)
{
	int *s = (int *)malloc((N + 1)*sizeof(int));
	int top = 0;

	int i;
	for (i = 1; i <= N; ++i)
		if (!adjList[i].inDegree)
			s[top++] = i;

	int e;
	struct arcNode*p;
	int count = 0;

	while (top)
	{
		e = s[--top];
		count++;
		for (p = adjList[e].firstArc; p; p = p->nextArc)
			if (--adjList[p->node].inDegree == 0)
				s[top++] = p->node;
	}

	if (count < N)
		return 0;
	else
		return 1;
}

int main()
{
	int N;
	scanf("%d", &N);

	struct adjListNode *adjList = (struct adjListNode*)malloc((N + 1)*sizeof(struct adjListNode));

	int i;
	for (i = 1; i <= N;++i)
	{
		adjList[i].inDegree = 0;
		adjList[i].inDegree = NULL;
	}

	struct arcNode*p;
	int j, k;
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &j);
		while (j--)
		{
			scanf("%d", &k);
			p = (struct arcNode*)malloc(sizeof(struct arcNode));
			p->nextArc = adjList[k].firstArc;
			p->node = i;
			adjList[k].firstArc = p;
			adjList[i].inDegree++;
		}
	}

	printf("%d", TopoSort(adjList, N));

	return 0;
}
