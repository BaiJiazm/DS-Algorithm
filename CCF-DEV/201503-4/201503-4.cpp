#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

vector< vector<int> >tree;
int maxL;

int maxLevel(int r) {
	int m1=0,m2=0;
	int size=tree[r].size();
	int i;
	for (i=0; i<size; ++i) {
		int l=maxLevel(tree[r][i]);
		if(l>m2) {
			m2=min(m1,l);
			m1=max(m1,l);
		}
	}
	maxL=max(maxL,m1+m2);
	return max(m1,m2)+1;
}

int main() {
	int m,n;
	while(scanf("%d %d",&n,&m)!=EOF) {
		tree.clear();
		tree.resize(n+m+1);
		int i,r;
		for (i=2; i<=n; ++i) {
			scanf("%d",&r);
			tree[r].push_back(i);
		}
		for (i=1; i<=m; ++i) {
			scanf("%d",&r);
			tree[r].push_back(n+i);
		}
		maxL=0;
		maxLevel(1);
		printf("%d\n",maxL);
	}
	return 0;
}
