/*
    非常简单的BFS,但是结果忘记用long long int 来保存导致80分。
    其实是考虑到了结果，但是还是百密一疏少乘了1000，1000*1000*1000*1000(最后1k是时间)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<tr1/unordered_map>
#include<algorithm>
using namespace std;
using namespace std::tr1;

#define NMAX 1010

struct posNode {
	int x;
	int y;
};

int graph[NMAX][NMAX];
//unordered_map<int,int>order;
unordered_map<int,pair<int,int> >order;

long long BFS(queue<posNode >&q,int n,int k) {
	long long int cost=0;
	int step=0;
	int countServe=0;
	int dir[4][2]= {{-1,0},{1,0},{0,-1},{0,1}};

	queue<posNode>qq;

	while(!q.empty()) {
		++step;
		while(!q.empty()) {
			posNode pn=q.front();
			q.pop();

			int i;
			for (i=0; i<4; ++i) {
				int x=pn.x+dir[i][0];
				int y=pn.y+dir[i][1];
				if (!graph[x][y]) {
					graph[x][y]=4;
					qq.push({x,y});
				} else if (graph[x][y]==2) {
					graph[x][y]=5;
					qq.push({x,y});
					cost+=order[x*n+y].first*step;
					countServe+=order[x*n+y].second;
				}
			}
		}
		if (countServe>=k)
			return cost;
		swap(q,qq);
	}
	return cost;
}

int main() {
	int m,n,k,d;
	while(scanf("%d %d %d %d",&n,&m,&k,&d)!=EOF) {
		memset(graph,0,sizeof(graph));
		order.clear();
		queue<posNode>q;

		int i,j,x,y,c;
		for (i=0,j=n+1; i<=j; ++i)
			graph[i][0]=graph[i][j]=graph[0][i]=graph[j][i]=4;

		for (i=0; i<m; ++i) {
			scanf("%d %d",&x,&y);
			graph[x][y]=1;
			q.push({x,y});
		}
		for (i=0; i<k; ++i) {
			scanf("%d %d %d",&x,&y,&c);
			if (!graph[x][y]) {
				graph[x][y]=2;
				if (order.count(x*n+y)==0)
					order[x*n+y]= {c,1};
				else {
					order[x*n+y].first+=c;
					order[x*n+y].second++;
				}
			}
		}
		for (i=0; i<d; ++i) {
			scanf("%d %d",&x,&y);
			graph[x][y]=3;
		}

		printf("%lld\n",BFS(q,n,k));
	}
	return 0;
}
