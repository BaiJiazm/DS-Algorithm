//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//#define INF 0xffff
//
//int localMST(int **exsitAdj, int **notAdj, int N)
//{
//	int *visit = (int *)malloc((N + 1)*sizeof(int));
//	int *queue = (int *)malloc((N + 1)*sizeof(int));
//	int *distance = (int *)malloc((N + 1)*sizeof(int));
//	
//	int i, j, k;
//	for (i = 1; i <= N; ++i)
//	{
//		visit[i] = 0;
//		distance[i] = notAdj[1][i];
//	}
//
//	int cost = 0;
//	int min = 1;
//	int w;
//	int head = 0, tail = 0;
//
//	distance[min] = 0;
////	visit[min] = 1;
//
//	for (i = 1; i <= N;i++)
//	{
//		for (j = 1,w=INF; j <= N;++j)
//			if (!visit[j] && w > distance[j])
//			{
//				min = j;
//				w = distance[j];
//			}
//        
//		visit[min] = 1;
//		cost += distance[min];
//		
//		for (j = 1,head=0,tail=0; j <= N; ++j)
//			if (!visit[j] && exsitAdj[min][j] != INF)
//			{
//				queue[tail++] = j;
//				visit[j] = 1;
//			}
//
//		while (head < tail)
//		{
//			k = queue[head++];
//			i++;
//			for (j = 1; j <= N; ++j)
//			    if (!visit[j])
//				    if (notAdj[k][j] < notAdj[min][j])
//					    notAdj[min][j] = notAdj[k][j];
//					else if (exsitAdj[k][j] != INF)
//					{
//						queue[tail++] = j;
//						visit[j] = 1;
//					}
//		}
//
//		for (j = 1; j <= N; ++j)
//			if (!visit[j] && notAdj[min][j] < distance[j])
//				distance[j] = notAdj[min][j];
//	}
//	return cost;
//}
//
//int main()
//{
//	int N;
//	scanf("%d", &N);
//
//	int **exsitAdj = (int**)malloc((N + 1)*sizeof(int *));
//	int **notAdj = (int**)malloc((N + 1)*sizeof(int *));
//
//	int i, j;
//	for (i = 1; i <= N; ++i)
//	{
//		exsitAdj[i] = (int *)malloc((N + 1)*sizeof(int));
//		notAdj[i] = (int *)malloc((N + 1)*sizeof(int));
//		for (j = 1; j <= N; ++j)
//			exsitAdj[i][j] = notAdj[i][j] = INF;
//	}
//
//
//	int v1, v2, w, s;
//	for (i = 0, j = N*(N - 1) / 2; i < j; ++i)
//	{
//		scanf("%d%d%d%d", &v1, &v2, &w, &s);
//		if (s)
//			exsitAdj[v1][v2] = exsitAdj[v2][v1] = w;
//		else
//			notAdj[v1][v2] = exsitAdj[v2][v1] = w;
//	}
//
//	printf("%d", localMST(exsitAdj, notAdj, N));
//
//	return 0;
//}
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#define INF 0x3f3f3f3f  
const int maxn = 117;
int m[maxn][maxn];
int vis[maxn], low[maxn];
int n;
int prim()
{
	vis[1] = 1;
	int sum = 0;
	int pos, minn;
	pos = 1;
	for (int i = 1; i <= n; i++)
	{
		low[i] = m[pos][i];
	}
	for (int i = 1; i < n; i++)
	{
		minn = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && minn > low[j])
			{
				minn = low[j];
				pos = j;
			}
		}
		sum += minn;
		vis[pos] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && low[j] > m[pos][j])
			{
				low[j] = m[pos][j];
			}
		}
	}
	return sum;
}
int main()
{
	int a, b, c, d;
	while (~scanf("%d", &n))
	{
		int nn = n*(n - 1) / 2;
		memset(vis, 0, sizeof(vis));
		memset(m, 0, sizeof(m));
		for (int i = 1; i <= nn; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if (d == 0)//未修建的才建图  
			{
				m[a][b] = c;
				m[b][a] = c;
			}

		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}