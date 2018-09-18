#include <bits/stdc++.h>
using namespace std;

#define NMAX 1005

vector<int> G[NMAX];
vector<int> FG[NMAX];
int vis[NMAX];
int cnt;

void dfs(int s, vector<int> g[NMAX]) {
	if(vis[s])
		return ;
	vis[s]=++cnt;
	for(int i=0; i<g[s].size(); ++i) {
		dfs(g[s][i], g);
	}
}

int solve(int s, vector<int> g[NMAX]) {
	memset(vis, 0, sizeof(vis));
	cnt=0;
	dfs(s, g);
	return cnt;
}

int main() {
	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		int i, u, v;
		for(i=0; i<NMAX; ++i) {
			G[i].clear();
			FG[i].clear();
		}
		for(i=0; i<m; ++i) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			FG[v].push_back(u);
		}
		int ans=0;
		for(i=1; i<=n; ++i) {
			if(solve(i, G)<solve(i, FG))
				++ans;
		}
		printf("%d\n", ans);
	}

	return 0;
}
