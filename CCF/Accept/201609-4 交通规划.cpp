#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<bitset>
#include<cstring>
#include<numeric>
using namespace std;

#define INF 0x3f3f3f3f
#define NMAX 10000
int minDijstra(const vector<vector<pair<int, int> > >&graph, int n) {
	bitset<NMAX>visited(0);
	int dist[NMAX];
	int path[NMAX];
	memset(dist, INF, sizeof(dist));
	memset(path, INF, sizeof(path));
	dist[0] = 0;
	path[0] = 0;
	int ans = 0;

	int i, j;
	int w, cur = 0, next;
	for (i = 0; i < n; ++i) {
		for (j = 0, w = INF; j < n; ++j)
			if (!visited[j] && dist[j] < w) {
				w = dist[j];
				next = j;
			}
		cur = next;
		visited[cur] = true;
		for (j = 0; j < (int)graph[cur].size(); ++j) {
			const pair<int, int>&p = graph[cur][j];
			if (!visited[p.first]) {
				int curd = p.second + dist[next];
				if (curd < dist[p.first]) {
					dist[p.first] = curd;
					path[p.first] = p.second;
				} else if (curd == dist[p.first] && p.second < path[p.first])
					path[p.first] = p.second;
			}
		}
	}
	return accumulate(path, path + n, 0);
}

int main() {
	//	freopen("test.txt","r",stdin);
	//	freopen("testOut.txt","w",stdout);

	int n, m;
	int a, b, c;
	while (scanf("%d %d", &n, &m) != EOF) {
		vector<vector<pair<int, int> > >graph(n, vector < pair<int, int> >());
		int i;
		for (i = 0; i < m; ++i) {
			scanf("%d %d %d", &a, &b, &c);
			--a, --b;
			graph[a].push_back({ b,c });
			graph[b].push_back({ a,c });
		}
		printf("%d\n", minDijstra(graph, n));
	}
	return 0;
}
