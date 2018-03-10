#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
	int v, c, flag;
	Node (int _v = 0, int _c = 0, int _flag = 0) : v(_v), c(_c), flag(_flag) {}
	bool operator < (const Node &rhs) const {
		return c > rhs.c;
	}
};

struct Edge {
	int v, cost;
	Edge (int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge>E[maxn];
bool vis[maxn][2];
int dist[maxn][2];

void Dijkstra(int n, int s) {
	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		dist[i][0] = INF;
		dist[i][1] = INF;
	}
	priority_queue<Node>que;
	dist[s][0] = 0;
	que.push(Node(s, 0, 0));
	while (!que.empty()) {
		Node tep = que.top();
		que.pop();
		int u = tep.v;
		int flag = tep.flag;
		if (vis[u][flag]) continue;
		vis[u][flag] = true;
		for (int i = 0; i < (int)E[u].size(); i++) {
			int v = E[u][i].v;
			int cost = E[u][i].cost;
			if (!vis[v][0] && dist[v][0] > dist[u][flag] + cost) {
				dist[v][1] = dist[v][0];
				dist[v][0] = dist[u][flag] + cost;
				que.push(Node(v, dist[v][0], 0));
				que.push(Node(v, dist[v][1], 1));
			} else if (!vis[v][1] && dist[v][1] > dist[u][flag] + cost) {
				dist[v][1] = dist[u][flag] + cost;
				que.push(Node(v, dist[v][1], 1));
			}
		}
	}
}

void addedge(int u, int v, int w) {
	E[u].push_back(Edge(v, w));
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, v, w;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i <= n; i++) E[i].clear();
		for (int u = 1; u <= n; u++) {
			scanf("%d", &m);
			for (int j = 0; j < m; j++) {
				scanf("%d%d", &v, &w);
				addedge(u, v, w);
			}
		}
		Dijkstra(n, 1);
		printf("%d\n", dist[n][1]);
	}
	return 0;
}
