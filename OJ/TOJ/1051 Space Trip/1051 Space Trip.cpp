#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=105;
struct node {
	int from;
	int to;
	int dis;
	bool operator < (const node&ths) const {
		return dis>ths.dis;
	}
};

int N,M,K;
int edge[maxn][maxn];
int dis[maxn][maxn];
bool oppo[maxn][maxn];
bool vis[maxn][maxn];

void init() {
	memset(edge,0x3f,sizeof (edge));
	memset(dis,0x3f,sizeof (dis));
	memset(oppo,false,sizeof(oppo));
	memset(vis,false,sizeof (vis));
}
int dijkstra() {
	dis[1][1]=0;
	priority_queue<node>q;
	int i;
	for(i=2; i<=N; ++i)
		if (!oppo[1][i]) {
			dis[1][i]=0;
			q.push({1,i,0});
		}
	while(!q.empty()) {
		node tn=q.top();
		q.pop();
		if (vis[tn.from][tn.to])
			continue;
		vis[tn.from][tn.to]=true;
		for (i=1; i<=N; ++i)
			if (!oppo[tn.from][i]&&tn.dis+edge[tn.from][i]<dis[i][tn.to]) {
				dis[i][tn.to]=tn.dis+edge[tn.from][i];
				q.push({i,tn.to,dis[i][tn.to]});
			}
	}
	return* min_element(dis[N]+1,dis[N]+N+1);
}

int main() {
	init();
	scanf("%d %d",&N,&M);
	int i,a,b,c;
	for(i=0; i<M; ++i) {
		scanf("%d %d %d",&a,&b,&c);
		edge[a][b]=c;
	}
	scanf("%d",&K);
	for(i=0; i<K; ++i) {
		scanf("%d %d",&a,&b);
		oppo[a][b]=oppo[b][a]=true;
	}
	printf("%d\n",dijkstra());
	return 0;
}
