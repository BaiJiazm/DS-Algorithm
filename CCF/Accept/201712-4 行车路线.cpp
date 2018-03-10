/* 这个题目真的还不错，需要比较扎实的基础功和算法的理解。不能生搬硬套算法，需要好好理解后运用。 
 * 另附一个错误解法，但是竟然能够得80分，说明对于ccf这种考试，得分并不难，在最后时间有限的情况下，多得分才是王道。 
 */
  
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

#define inf 0x3f3f3f3f
using namespace std;

int N,M;
int g[501][501];
long long g1[501][501];  //大路和小路
long long dis[501],dis1[501];
bool vis[501];

void SPFA(int s) {
	queue<int> Q;
	dis[s] = 0;
	dis1[s]=0;
	Q.push(s);
	vis[s] = 1;
	while (!Q.empty()) {
		long long tep = Q.front();
		Q.pop();
		vis[tep] = 0;
		for (int i=1; i<=N; i++) {
			if(dis[i]>dis[tep]+g[tep][i]) { //大路+大路
				dis[i] = dis[tep] + g[tep][i];
				if (vis[i] == 0) {
					Q.push(i);
					vis[i] = 1;
				}
			}
			if(dis[i]>dis1[tep]+g[tep][i]) { //小路+大路
				dis[i] = dis1[tep] + g[tep][i];
				if (vis[i] == 0) {
					Q.push(i);
					vis[i] = 1;
				}
			}
			if(g1[tep][i]!=inf) { //可以走小路,由于之前已经把小路进行了归并，所以只考虑之前走的是大路
				if(dis1[i]>dis[tep]+g1[tep][i]*g1[tep][i]) {
					dis1[i]=dis[tep]+g1[tep][i]*g1[tep][i];
					if (vis[i] == 0) {
						Q.push(i);
						vis[i] = 1;
					}
				}
			}
		}
	}
}

int main() {
	int t,a,b,c;
	scanf("%d %d", &N, &M);
	memset(vis, 0, sizeof(vis));
	memset(dis, inf, sizeof(dis));
	memset(dis1,inf,sizeof(dis1));
	memset(g,inf,sizeof(g));
	memset(g1,inf,sizeof(g1));
	while (M--) {
		scanf("%d %d %d %d",&t, &a, &b, &c);
		if(t==1&&c<g1[a][b])
			g1[a][b]=g1[b][a]=c;
		else if(t==0&&c<g[a][b])
			g[a][b]=g[b][a]=c;
	}
	for(int i=1; i<=N; i++) //这里用floyd事先计算好只走小路时两两点之间的最短距离
		for(int j=i+1; j<=N; j++) {
			for(int k=1; k<=N; k++) {
				if(k==i||k==j)
					continue;
				if(g1[i][j]>g1[i][k]+g1[k][j])
					g1[i][j]=g1[j][i]=g1[i][k]+g1[k][j];
			}
		}
	SPFA(1);
	printf("%lld\n", min(dis[N],dis1[N]));
	return 0;
}


//80分错误解法
 
//#include<bits/stdc++.h>
//using namespace std;
//const long long INF = 1e18;
//int n,m;
//struct node {
//	int to;
//	long long cost;
//};
//
//struct edge {
//	int id;
//	long long cost;
//	int len;
//	bool operator < (const edge & a)const {
//		return cost > a.cost;
//	}
//};
//
//vector<node> G[510][2];
//long long d[510];
//priority_queue<edge>que;
//
//long long p2(long long a) {
//	return a * a;
//}
//
//int solve() {
//	fill(d,d+n+1,INF);
//	d[1] = 0;
//	que.push({1,0,0});
//	while(!que.empty() ) {
//		edge a = que.top();
//		que.pop();
//		int v = a.id;
//		if(v == n)
//			break;
//		if(d[v] < a.cost)
//			continue;
//		for(int i=0; i<G[v][0].size(); i++) {
//			node e = G[v][0][i];
//			if(d[e.to] > d[v] + e.cost) {
//				d[e.to] = d[v] + e.cost;
//				que.push(edge {e.to,d[e.to],0});
//			}
//		}
//		for(int i=0; i<G[v][1].size(); i++) {
//			node e = G[v][1][i];
//			int cost = p2(a.len+e.cost)-p2(a.len);
//			if(d[e.to] > d[v] + cost) {
//				d[e.to] = d[v] + cost;
//				que.push(edge {e.to,d[e.to],a.len+e.cost});
//			}
//		}
//	}
//	return d[n];
//}
//
//int main () {
//	scanf("%d %d",&n,&m);
//	for(int i=1; i<=m; i++) {
//		int t,a,b;
//		long long c;
//		scanf("%d %d %d %lld",&t,&a,&b,&c);
//		G[a][t].push_back({b,c});
//		G[b][t].push_back({a,c});
//	}
//	cout << solve() <<endl;
//	return 0;
//}
