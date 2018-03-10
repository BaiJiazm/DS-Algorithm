#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

void init(vector<int>&fa,int n) {
	for (int i=0; i<n; ++i)
		fa[i]=i;
}

int findFather(vector<int>&fa,int r) {
	if (fa[r]!=r)
		fa[r]=findFather(fa,fa[r]);
	return fa[r];
}

void Union (vector<int>&fa,int u,int v) {
	int ufa=findFather(fa,u);
	int vfa=findFather(fa,v);
	if (ufa<vfa)
		fa[v]=fa[vfa]=ufa;
	else
		fa[u]=fa[ufa]=vfa;
}

int main() {
	int n,m;
	while(~scanf("%d %d",&n,&m)) {
		if(!n&&!m)
			break;
		if (!m) {
			printf("%d\n",1);
			continue;
		}
		vector<int>fa(n);
		init(fa,n);
		int i,j,s,t;
		for(i=0; i<m; ++i) {
			int k;
			scanf("%d",&k);
			for (j=0; j<k; ++j) {
				if (!j)
					scanf("%d",&s);
				else {
					scanf("%d",&t);
					Union(fa,s,t);
				}
			}
		}
		int ans=0;
		for (i=0; i<n; ++i)
			if (!findFather(fa,i))
				++ans;
		printf("%d\n",ans);
	}
	return 0;
}


//下面这种带秩的并查集没有我写的快，其实节点本身编号就能作为唯一标识，将最小编号作为集合定点 
#include <iostream>
using namespace std;
int n, m, k, t, f, p[30001], rank[30001], a, b;
int find(int x) {
	if (x == p[x]) return x;
	else return p[x] = find(p[x]);
}
void un(int x, int y) {
	a = find(x);
	b = find(y);
	if (a == b)
		return;
	if (rank[a] > rank[b])
		p[b] = a;
	else {
		p[a] = b;
		if (rank[a] == rank[b])
			rank[b]++;
	}
}
int main() {
	int i, sum;
	while (cin >> m >> n && (m || n)) {
		for (i = 0; i < m; i++) {
			p[i] = i;
			rank[i] = 0;
		}
		for (i = 0; i < n; i++) {
			cin >> k;
			if (k >= 1)
				cin >> f;
			for (int j = 1; j < k; j++) {
				cin >> t;
				un(f, t);
			}
		}
		sum = 1;
		for (i = 1; i < m; i++) {
			if (find(i) == find(0))
				sum++;
		}
		cout << sum << endl;
	}
	return 0;
}
