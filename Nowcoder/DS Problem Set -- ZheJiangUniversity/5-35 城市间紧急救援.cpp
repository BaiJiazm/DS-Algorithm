//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Max_Int 2147483647

void latestPath(int **adjMatrix, int N,int **path,int *pathNum,int *rescue,int *cost, int *distance,int start,int end)
{
	int *visit = (int *)malloc(N*sizeof(int));

	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
			path[i][j] = -1;
		
		visit[i] = 0;
		cost[i] = 0;
		pathNum[i] = 0;

		distance[i] = adjMatrix[start][i];
        
		if (distance[i] < Max_Int)
		{
			path[i][i] = start;
			cost[i] = rescue[start] + rescue[i];
			pathNum[i]++;
		}
	}

	visit[start] = 1;
	distance[start] = 0;
	pathNum[start] = 1;
	cost[start] = rescue[start];


	int now, k;
	int w;

	for (i = 1 ; i < N; ++i)
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
					path[j][j] = now;
					cost[j] = cost[now] + rescue[j];

					pathNum[j] = pathNum[now];
				}
				else if (w + adjMatrix[now][j] == distance[j])
				{
					pathNum[j] += pathNum[now];
					if (cost[j] < cost[now] + rescue[j])
					{
						for (k = 0; k < N; ++k)
							path[j][k] = path[now][k];
						path[j][j] = now;

						cost[j] = cost[now] + rescue[j];
					}
				}
		}
	}
	return;
}

void printPath(int *path,int p)
{
	if (p == -1)
		return;
	printPath(path, path[p]);

	printf("%d ", p);
}
int main()
{
	int N;
	int M;
	scanf("%d%d", &N, &M);

	int start, end;
	scanf("%d%d", &start, &end);

	int *rescue = (int *)malloc(N*sizeof(int));

	int i, j;
	for (i = 0; i < N; ++i)
		scanf("%d", rescue + i);

	int **adjMatrix = (int **)malloc(N*sizeof(int *));
	int **path = (int **)malloc(N*sizeof(int *));
	int *pathNum = (int *)malloc(N*sizeof(int));
	int *distance = (int *)malloc(N*sizeof(int));
	int *cost = (int *)malloc(N*sizeof(int));

    for (i = 0; i < N; ++i)
	{
		adjMatrix[i] = (int *)malloc(N *sizeof(int));
		path[i] = (int *)malloc(N *sizeof(int));
		for (j = 0; j < N; ++j)
		{
			adjMatrix[i][j] = Max_Int;
			path[i][j] = 0;
		}
	}

	int v1, v2, w;
	for (i = 0; i < M; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &w);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
	}

	latestPath(adjMatrix, N, path,pathNum, rescue, cost, distance, start, end);

	printf("%d ", pathNum[end]);
	
	printf("%d\n", cost[end]);

	printPath(path[end], path[end][end]);
	printf("%d", end);

	return 0;
}
//
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <queue>  
using namespace std;  
const int inf = 0x3f3f3f3f;  
int N, M, S, D;  
int map[550][550];  
int val[550], dis[550], vis[550], cnt[550], sum[550], pre[550];
//每点权值   距S距离   标记      路径数量  最大救援队  前驱   
void path(int d) {  
    if(pre[d] != -1) {  
        path(pre[d]);  
        printf("%d ", pre[d]);  
    }  
}  
int main() {  
    scanf("%d %d %d %d", &N, &M, &S, &D);  
    int i, j;  
    for(i = 0; i < N; i++) {  
        scanf("%d", val + i);  
    }  
    for(i = 0; i < N; i++) {  
        for(j = 0; j < N; j++) {  
            if(i == j) map[i][j] = 0;  
            else map[i][j] = inf;  
        }  
    }  
    int x, y, z;  
    for(i = 0; i < M; i++) {  
        scanf("%d %d %d", &x, &y, &z);  
        map[x][y] = z;  
        map[y][x] = z;  
    }  
    for(i = 0; i < N; i++) {  //初始化   
        dis[i] = inf;  
        vis[i] = 0;  
        cnt[i] = 0;  
        sum[i] = 0;  
        pre[i] = -1;  
    }  
    dis[S] = 0;  //初始化起始点   
    vis[S] = 1;  
    cnt[S] = 1; //起点到其本身方式为1   
    sum[S] = val[S];  
    for(i = 0; i < N; i++) {  
        int minn = inf, mini = S;  
         for(j = 0; j < N; j++) {  
            if(vis[j] == 0 && minn > dis[j]) {  
                minn = dis[j];  
                mini = j;  
            }  
        }  
        vis[mini] = 1;  
        for(j = 0; j < N; j++) {  
            if(vis[j] == 0) {  
                if(dis[j] > dis[mini] + map[mini][j]) {  
                    dis[j] = dis[mini] + map[mini][j];  
                    sum[j] = sum[mini] + val[j];  
                    cnt[j] = cnt[mini];  //方式等于到达前驱的方式   
                    pre[j] = mini;  
                }  
                else if(dis[j] == dis[mini] + map[mini][j]) {  
                    cnt[j] = cnt[mini] + cnt[j]; //两种方式距离相等，则方式数相加   
                    if(sum[j] < sum[mini] + val[j]) {  //能获得更大的救援，则更新   
                        sum[j] = sum[mini] + val[j];  
                        pre[j] = mini;  
                    }  
                }  
            }  
        }  
    }  
    printf("%d %d\n", cnt[D], sum[D]);  
    path(D);  
    printf("%d\n", D);  
    return 0;  
} 

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define INF 0xffffff


void dijkstra(int **adjMatrix, int N, int *help, int *totalHelp, int *path, int *distance, int *count, int S, int D)
{
	int *visit = (int *)malloc((N + 1)*sizeof(int));

	int i, j;
	for (i = 0; i < N; ++i)
	{
		distance[i] = adjMatrix[S][i];
		visit[i] = 0;

		if (distance[i] != INF)
		{
			path[i] = S;
			totalHelp[i] = help[i] + help[S];
			count[i] = 1;
		}
		else
		{
			path[i] = -1;
			totalHelp[i] = 0;
			count[i] = 0;
		}
	}

	totalHelp[S] = help[S];
	distance[S] = 0;
	count[S] = 1;
	visit[S] = 1;

	int w;
	int cur;

	for (i = 0; i < N; ++i)
	{
		for (j = 0, w = INF; j < N; ++j)
			if (!visit[j] && distance[j] < w)
			{
				cur = j;
				w = distance[j];
			}

		visit[cur] = 1;

		//if (cur == D)
		//	return;

		for (j = 0; j < N; ++j)
			if (!visit[j])
				if (w + adjMatrix[cur][j] < distance[j])
				{
					totalHelp[j] = totalHelp[cur] + help[j];
					distance[j] = w + adjMatrix[cur][j];
					count[j] = count[cur];
					path[j] = cur;
				}
				else if (w + adjMatrix[cur][j] == distance[j])
				{
					count[j] += count[cur];
					if (totalHelp[j] < totalHelp[cur] + help[j])
					{
						totalHelp[j] = totalHelp[cur] + help[j];
						path[j] = cur;
					}
				}
	}
}

void printPath(int *path,int p)
{
	if (p == -1)
		return;
	printPath(path, path[p]);

	printf("%d ", p);
}

int main()
{
	int N, M, S, D;
	scanf("%d%d%d%d", &N, &M, &S, &D);

	int** adjMatrix = (int **)malloc((N + 1)*sizeof(int*));
	int *help = (int *)malloc((N + 1)*sizeof(int));
	int *totalHelp = (int *)malloc((N + 1)*sizeof(int));
	int *path = (int *)malloc((N + 1)*sizeof(int));
	int *count = (int *)malloc((N + 1)*sizeof(int));
	int *distance = (int *)malloc((N + 1)*sizeof(int));

	int i, j;
	int v1, v2, w;
	for (i = 0; i < N; ++i)
		scanf("%d", help + i);

	for (i = 0; i < N; ++i)
	{
		adjMatrix[i] = (int*)malloc((N + 1)*sizeof(int));
		for (j = 0; j < N; ++j)
			adjMatrix[i][j] = INF;
	}

	for (i = 0; i < N; ++i)
	{
		scanf("%d%d%d", &v1, &v2, &w);
		adjMatrix[v1][v2] = adjMatrix[v2][v1] = w;
	}

	dijkstra(adjMatrix, N, help, totalHelp, path, distance, count, S, D);

	printf("%d %d\n", count[D], totalHelp[D]);

	printPath(path, path[D]);
	printf("%d", D);

	return 0;
}
