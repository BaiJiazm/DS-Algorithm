#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

#define N 10001
#define INF 0x3f3f3f3f

class Edge {
	public:
		int to;
		int len;
};
class Node {
	public:
		int id;
		int len;
		int cost;
		bool operator < (const Node& nd) const {
			return !(cost<nd.cost||cost==nd.cost&&len<nd.len);
		}
};

int n, m;
vector<Edge> g[N];

int solve() {
	priority_queue<Node>q;
	int dist[N];
	int path[N];
	int vis[N];
	fill(dist, dist+N, INF);
	fill(path, path+N, INF);
	fill(vis, vis+N, 0);
	q.push(Node {1, 0, 0});

	int i;
	while(!q.empty()) {
		Node nd=q.top();
		q.pop();
		if(vis[nd.id])
			continue;
		vis[nd.id]=true;
		dist[nd.id]=nd.cost;
		path[nd.id]=nd.len;
		for(i=0; i<g[nd.id].size(); ++i) {
			Edge &e=g[nd.id][i];
			if(!vis[e.to]&&dist[e.to]>nd.cost+e.len) {
				q.push(Node {e.to, e.len, nd.cost+e.len});
			}
		}
	}
	return accumulate(path+1, path+n+1, 0);
}

int main() {
//	freopen("201609-4-test.txt", "r", stdin);
	int a,b,c;
	int i;
	while(scanf("%d %d", &n ,&m)!=EOF) {
		for (i=0; i<g[i].size(); ++i) {
			g[i].clear();
		}
		while(m--) {
			scanf("%d %d %d", &a, &b, &c);
			g[a].push_back(Edge {b, c});
			g[b].push_back(Edge {a, c});
		}
		cout<<solve()<<endl;
	}
	return 0;
}
