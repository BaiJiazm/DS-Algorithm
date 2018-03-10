//segment error 错误了，不知道为什么？	 
#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f

int N,M,C;
vector<vector<pair<int,int> > >graph;
vector<int>P;
vector<int>Q;
vector<int>price;

struct cmp {
	bool  operator () (const pair<int,int>&p1,const pair<int,int>&p2) {
		return p1.first>p2.first;
	}
};

void Dijistra(vector<int>&dis,int start) {
	dis.resize(N+1,INF);
	dis[start]=0;
	vector<bool>visited(N+1,false);
	priority_queue<pair<int,int>,vector<pair<int,int> >,cmp >q;

	q.push({0,start});
	while(!q.empty()) {
		pair<int,int> pir=q.top();
		q.pop();
		if (visited[pir.second])
			continue;
		visited[pir.second]=true;
		dis[pir.second]=pir.first;
		for (int i=0; i<graph[pir.second].size(); ++i) {
			pair<int,int>&edge=graph[pir.second][i];
			if (!visited[edge.first]&&edge.second+pir.first<=C)
				if (P[edge.first]) {
					dis[edge.first]=0;
					q.push({0,edge.first});
				} else if (edge.second+pir.first<dis[edge.first]) {
					dis[edge.first]=pir.first+edge.second;
					q.push({pir.first+edge.second,edge.first});
				}
		}
	}
}

int main() {
	while(cin>>N>>M>>C) {
		graph.resize(N+1);
		P.resize(N+1,0);
		Q.resize(N+1,0);
		price.resize(N+1);

		int i,a,b,c;
		for (i=0; i<M; ++i) {
			scanf("%d %d %d",&a,&b,&c);
			graph[a].push_back({b,c});
			//graph[b].push_back({a,c});
		}
		int p,t;
		cin>>t;
		for (i=0; i<t; ++i) {
			scanf("%d",&p);
			P[p]=1;
		}
		cin>>t;
		for (i=0; i<t; ++i) {
			scanf("%d %d",&p,&c);
			Q[p]=1;
			price[p]=c;
		}
		vector<int>last;
		vector<int>cost;
		Dijistra(last,1);
		if(last[N]==INF) {
			cout<<-1<<endl;
			continue;
		}
		Dijistra(cost,N);
		int maxProfit=-1;
		for (i=1; i<=N; ++i)
			if(Q[i]) {
				int sell=C-last[i]-cost[i];
				if (sell>0)
					maxProfit=max(maxProfit,sell*price[i]);
			}
		cout<<maxProfit<<endl;
	}
	return 0;
}


//以下是acm-book上的代码，ac! 

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 1500;
const long long INF = 0x3f3f3f3f;
struct Edge {
	int from, to, dist;
};
struct HeapNode {
	int d, u;
	bool operator  < (const HeapNode & rhs) const {
		return d > rhs.d;
	}
};

int pp[maxn], c;
struct Dijkstra {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n) {
		this -> n = n;
		for (int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int dist) {
		edges.push_back((Edge) {
			from, to, dist
		});
		m = edges.size();
		G[from].push_back(m-1);
	}
	void dijkstra(int s) {
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++) d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode) {
			0, s
		});
		while (!Q.empty()) {
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u]) continue;
			done[u] = true;
			for (int i = 0; i < (int)G[u].size(); i++) {
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist && d[u] + e.dist <= c) {
					d[e.to] = d[u] + e.dist;
					if (pp[e.to]) d[e.to] = 0;
					p[e.to] = G[u][i];
					Q.push((HeapNode) {
						d[e.to], e.to
					});
				}
			}
		}

	}
} G, H;

int q[maxn], left[maxn], city[maxn];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, x, y;
	while (scanf("%d%d%d", &n, &m, &c) != EOF) {
		H.init(n+1);
		G.init(n+1);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			H.AddEdge(u, v, w);
			G.AddEdge(v, u, w);
		}
		memset(pp, 0, sizeof(pp));
		memset(q, 0, sizeof(q));
		scanf("%d", &x);
		for (int i = 0; i < x; i++) {
			scanf("%d", &y);
			pp[y] = 1;
		}
		scanf("%d", &x);
		for (int i = 0; i < x; i++) {
			scanf("%d%d", &city[i], &q[i]);

		}
		H.dijkstra(1);
		if (H.d[n] == INF) {
			puts("-1");
			continue;
		}
		G.dijkstra(n);
		for (int i = 0; i < x; i++) left[city[i]] = c - H.d[city[i]];

		int ans = 0;
		for (int i = 0; i < x; i++)
			if(q[i] > 0 && left[city[i]] > 0 && left[city[i]] - G.d[city[i]] > 0)
				ans = max(ans, (left[city[i]] - G.d[city[i]]) * q[i]);
		printf("%d\n", ans);
	}
	return 0;
}
