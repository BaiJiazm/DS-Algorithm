#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
const double INF = 1000000000;

struct edge {
	int from, to, cost;
	edge() {}
	edge(int _from, int _to, int _cost) {
		from = _from;
		to = _to;
		cost = _cost;
	}
};

vector<int>G[maxn];
vector<edge> edges;
bool inque[maxn];
int dis[maxn];

void add(int u, int v, int w) {
	edges.push_back(edge(u, v, w));
	int m = edges.size();
	G[u].push_back(m-1);
}

int spfa(int n, int s) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	dis[s] = 0;
	inque[s] = true;
	queue<int>que;
	que.push(s);
	while (!que.empty()) {
		int u = que.front();
		inque[u] = false;
		que.pop();
		for (int i = 0; i < (int)G[u].size(); i++) {
			edge e = edges[G[u][i]];
			if (dis[e.to] > dis[u] + e.cost) {
				dis[e.to] = dis[u] + e.cost;
				if (!inque[e.to]) {
					que.push(e.to);
					inque[e.to] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dis[i]);
	return ans;
}

map<string, int> mp;

void init(int n) {
	for (int i = 0; i <= n; i++) G[i].clear();
	edges.clear();
	mp.clear();
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%d", &n) != EOF && n) {
		init(n);
		int cnt = 1;
		char a[20], b[20];
		for (int i = 0; i < n; i++) {
			scanf("%s", a);
			if (mp[a] == 0) mp[a] = cnt++;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%s%s", a, b);
			int u = mp[a], v = mp[b];
			add(u, v, 1);
			add(v, u, 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			ans = max(ans, spfa(n, i));
		}
		printf("%d\n", ans == INF ? -1 : ans);
	}
	return 0;
}
