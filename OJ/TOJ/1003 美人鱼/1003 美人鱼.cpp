#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 0x3f3f3f3f;

struct Node {
	int v, c, flag;	//节点、耗费、最次标记
	Node (int _v = 0, int _c = 0, int _flag = 0) : v(_v), c(_c), flag(_flag) {}
	bool operator < (const Node &rhs) const {
		return c > rhs.c;
	}
};
struct Edge {
	int v, cost;	//节点、耗费
	Edge (int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge>E[maxn];
bool vis[maxn][2];	//0,1分别表示最短和次短
int dist[maxn][2];
int cnt[maxn][2];

int Dijkstra(int s, int t) {
	memset(vis, false, sizeof(vis));
	memset(dist,0x3f,sizeof (dist));
	memset(cnt, 0, sizeof(cnt));

	priority_queue<Node>que;
	dist[s][0] = 0;
	cnt[s][0]=cnt[s][1]=1;
	que.push(Node(s, 0, 0));
	while (!que.empty()) {
		Node tep = que.top();
		que.pop();
		int u = tep.v;
		int flag = tep.flag;
		if (vis[u][flag])
			continue;
		vis[u][flag] = true;
		for (int i = 0; i < (int)E[u].size(); i++) {
			int v = E[u][i].v;
			int cost = E[u][i].cost;
			if (!vis[v][0] && dist[v][0] > dist[u][flag] + cost) {
				if (dist[v][0]==dist[u][flag]+cost+1) {
					dist[v][1] = dist[v][0];
					cnt[v][1]=1;
					que.push(Node(v, dist[v][1], 1));
				} else
					cnt[v][1]=0;
				dist[v][0] = dist[u][flag] + cost;
				cnt[v][0]=cnt[u][flag];
				que.push(Node(v, dist[v][0], 0));
			} else if (!vis[v][0] && dist[v][0] == dist[u][flag] + cost)
				cnt[v][0]+=cnt[u][flag];
			else if (!vis[v][1] && dist[v][0]+1 == dist[u][flag] + cost) {
				if (dist[v][1]==dist[v][0]+1) {
					cnt[v][1]+=cnt[u][flag];
				} else {
					cnt[v][1]=cnt[u][flag];
					dist[v][1] = dist[u][flag] + cost;
					que.push(Node(v, dist[v][1], 1));
				}
			}
		}
	}
	return cnt[t][0]+cnt[t][1];
}

void addedge(int u, int v, int w) {
	E[u].push_back(Edge(v, w));
}

int main() {
	int n, m, s, t;
	int i,j,a,b,c;
	while (scanf("%d %d", &n,&m) != EOF) {
		for (i = 0; i <= n; i++)
			E[i].clear();
		for (j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b,&c);
			addedge(a, b, c);
		}
		scanf("%d %d", &s, &t);
		printf("%d\n", Dijkstra(s, t));
	}
	return 0;
}
