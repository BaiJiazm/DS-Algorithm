//#include<iostream>
//#include<cstring>
//#include<functional>
//#include<numeric>
//using namespace std;
//const int maxm=1000;
//const int maxn=20;
//struct edge {
//	int to;
//	int cost;
//	int next;
//};
//
//int N,M,D;
//int tot;
//int sumHappy;
//struct edge e[maxm];
//int head[maxn];
//int d[maxn];
//
//int pathCost;
//int vis[maxn];
//int path[maxn];
//int ansPath[maxn];
//
//void init() {
//	tot=0;
//	memset(head,-1,sizeof (head));
//	pathCost=INT_MAX;
//	memset(vis,0,sizeof(vis));
//}
//void addedge(int u,int v,int c) {
//	e[tot]= {v,c,head[u]};
//	head[u]=tot++;
//}
//void dfs(int u,int n,int c,int tc) {
//	if (n==N&&tc<pathCost) {
//		pathCost=tc;
//		memcpy(ansPath,path,sizeof(path));
//		return ;
//	}
//	for(int i=head[u]; i!=-1; i=e[i].next) {
//		edge& eg=e[i];
//		if (!vis[eg.to]) {
//			vis[u]=true;
//			path[n]=eg.to;
//			dfs(eg.to,n+1,c+eg.cost,tc+c+eg.cost);
//			vis[u]=false;
//		}
//	}
//}
//int main() {
//	init();
//	cin>>N>>M>>D;
//	int i,u,v,c;
//	for (i=1; i<=N; ++i)
//		cin>>d[i];
//	sumHappy=accumulate(d+1,d+1+N,0);
//	for (i=1; i<=N; ++i) {
//		cin>>c;
//		addedge(0,i,c);
//	}
//	for (i=1; i<=M; ++i) {
//		cin>>u>>v>>c;
//		addedge(u,v,c);
//		addedge(v,u,c);
//	}
//	dfs(0,0,0,0);
//	printf("%.2lf\n",sumHappy-pathCost*1.0/D);
//	for (i=1; i<=N; ++i)
//		i?printf(" %d",ansPath[i]):printf("%d",ansPath[i]);
//	return 0;
//}

#include<iostream>
#include<cstdio>
#include<limits.h>
#include<cstring>
#include<vector>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;
const int maxm=1000;
const int maxn=20;
struct edge {
	int to;
	int cost;
	bool operator < (const edge &ths) const {
		return to<ths.to;
	}
};

int N,M,D;
int tot;
int sumHappy;
vector<edge> e[maxm];
int d[maxn];

int pathCost;
int vis[maxn];
int path[maxn];
int ansPath[maxn];

void init() {
	tot=0;
	pathCost=INT_MAX;
	memset(vis,0,sizeof(vis));
}
void dfs(int u,int n,int c,int tc) {
	if (n==N&&tc<pathCost) {
		pathCost=tc;
		memcpy(ansPath,path,sizeof(path));
		return ;
	}
	for(int i=0; i<e[u].size(); ++i) {
		edge& eg=e[u][i];
		if (!vis[eg.to]) {
			vis[eg.to]=true;
			path[n]=eg.to;
			dfs(eg.to,n+1,c+eg.cost,tc+c+eg.cost);
			vis[eg.to]=false;
		}
	}
}
int main() {
	init();
	cin>>N>>M>>D;
	int i,u,v,c;
	for (i=1; i<=N; ++i)
		cin>>d[i];
	sumHappy=accumulate(d+1,d+1+N,0);
	for (i=1; i<=N; ++i) {
		cin>>c;
		e[0].push_back({i,c});
	}
	for (i=1; i<=M; ++i) {
		cin>>u>>v>>c;
		e[u].push_back({v,c});
		e[v].push_back({u,c});
	}
	for (i=0; i<=N; ++i)
		sort(e[i].begin(),e[i].end());
	dfs(0,0,0,0);
	printf("%.2lf\n",sumHappy-pathCost*1.0/D+0.005);
	for (i=0; i<N; ++i)
		i?printf(" %d",ansPath[i]):printf("%d",ansPath[i]);
	return 0;
}
