#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define N 1001
int n,m;
vector<int>g[N];
vector<int>rg[N];
int vis[N];
int rvis[N];

void bfs(vector<int> g[], int s, int vis[]) {
	memset(vis, 0, sizeof(int)*N);
	queue<int>q;
	q.push(s);

	int i, t;
	while(!q.empty()) {
		int front=q.front();
		q.pop();
		if(vis[front])
			continue;
		vis[front]=true;
		for (i=0; i<g[front].size(); ++i) {
			t=g[front][i];
			if(!vis[t]) {
				q.push(t);
			}
		}
	}
	return ;
}

int main() {
//	freopen("201709-4-test.txt", "r", stdin);

	int a,b;
	int i, j, visnum;
	int ans;
	while(scanf("%d %d", &n, &m)!=EOF) {
		for (i=0; i<N; ++i) {
			g[i].clear();
			rg[i].clear();
		}
		while(m--) {
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			rg[b].push_back(a);
		}
		ans=0;
		for(i=1; i<=n; ++i) {
			bfs(g, i, vis);
			bfs(rg, i, rvis);
			visnum=0;
			for(j=1; j<=n; ++j)
				visnum+=vis[j]|rvis[j];
			ans+=visnum==n;
		}
		cout<<ans<<endl;
	}
	return 0;
}
