#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define N 100010

class Node {
	public:
		int from;
		int to;
		int cost;
		bool operator < (const Node& n) const {
			return cost>n.cost;
		}

};

class Edge {
	public:
		int to;
		int cost;
};

vector<Edge> g[N];
int n, m;

int solve() {
	priority_queue<Node>q;
	q.push(Node {1, 1, 0});
	vector<int>vis(N, 0);
	vector<int>dis(N, 0);
	int i;
	while(!q.empty()) {
		Node e=q.top();
		q.pop();
		if(vis[e.to])
			continue;
		vis[e.to]=true;
		dis[e.to]=max(e.cost, dis[e.from]);
		for (i=0; i<g[e.to].size(); ++i) {
			Edge& t=g[e.to][i];
			if(vis[t.to])
				continue;
			q.push(Node {e.to, t.to, t.cost});
		}
	}
	return dis[n];
}

int main() {
	int a, b, c;
	while(scanf("%d %d", &n, &m)!=EOF) {
		for(int i=0; i<N; ++i) {
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
