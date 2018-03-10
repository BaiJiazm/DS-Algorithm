/* 尚有两种未知情况未通过测试 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int NodeN;
int arcN;
int start;

int *vertexs;
int *visitPath;
int **adjMatrix;

int visitNodeN = 0;

void input()
{
	scanf("%d %d %d", &NodeN, &arcN, &start);

	vertexs = (int *)malloc((NodeN + 1)*sizeof(int));
	visitPath = (int *)malloc((NodeN + 1)*sizeof(int));
	adjMatrix = (int **)malloc((NodeN + 1)*sizeof(int *));
	
	int i, j;
	for (i = 1; i <= NodeN; ++i)
	{
		adjMatrix[i] = (int *)malloc((NodeN+1)*sizeof(int));
		for (j = 1; j <= NodeN; ++j)
			adjMatrix[i][j] = 0;
		vertexs[i] = 0;
	}

	int v1, v2;
	for (i = 1; i <= arcN; i++)
	{
		scanf("%d %d", &v1, &v2);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = 1;
	}
}

void DFS0(int s)
{
	if (!vertexs[s])
	{
		visitPath[++visitNodeN] = s;
		vertexs[s] = 1;
	}
	int i;
	for (i = 1; i <= NodeN; ++i)
		if (!vertexs[i] && adjMatrix[s][i])
			DFS0(i);

}

void DFS(int s)
{
	visitPath[++visitNodeN] = s;
	vertexs[s] = 1;
	
	int i;
	for (i = 1; i <= NodeN; ++i)
		if (!vertexs[i] && adjMatrix[s][i])
			DFS(i);

}
void outPut()
{
	int i;
	for (i = 1; i <= visitNodeN; ++i)
		if (i == 1)
			printf("%d", visitPath[i]);
		else
			printf(" %d", visitPath[i]);

	for (--i,--i; i >= 1; --i)
		printf(" %d", visitPath[i]);

	if (visitNodeN < NodeN)
		printf(" 0");
}
int main()
{
	input();

	DFS(start);

	outPut();

	return 0;
}

//#include<stdio.h>
//
//void DFS(int(Vertex[])[1003], int V, int *Visit, int N) {
//	Visit[V] = 1;
//	int i;
//	for (i = 1; i <= N; i++) {
//		if (Vertex[V][i] == 1) {
//			if (Visit[i] == 0) {
//				Visit[i] = 1;
//				printf(" %d", i);
//				DFS(Vertex, i, Visit, N);
//				printf(" %d", V);
//			}
//		}
//	}
//}
//
//
//int main() {
//	int i, N, M, S;
//	scanf("%d%d%d", &N, &M, &S);
//	int Vertex[N + 1][1003];
//	int E1, E2, j;
//	int Visit[1003];
//	for (i = 1; i <= N; i++) {
//		for (j = 1; j <= N; j++) {
//			Vertex[i][j] = 0;
//		}
//		Visit[i] = 0;
//	}
//	for (i = 1; i <= M; i++) {
//		scanf("%d%d", &E1, &E2);
//		Vertex[E1][E2] = Vertex[E2][E1] = 1;
//	}
//	printf("%d", S);
//	DFS(Vertex, S, Visit, N);
//	for (i = 1; i <= N; i++) {
//		if (Visit[i] == 0) {
//			printf(" 0");
//			return 0;
//		}
//	}
//	return 0;
//}