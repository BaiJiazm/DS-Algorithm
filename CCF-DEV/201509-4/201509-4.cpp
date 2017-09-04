#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

vector< vector<int> >graph;
vector<bool>onstack;
stack<int>stk;
vector<int>dfn;
vector<int>low;
int cnt=1;
int ans=0;

void tarjan(int r) {
	onstack[r]=true;
	stk.push(r);
	dfn[r]=low[r]=++cnt;

	int i;
	vector<int>::iterator it;
	for (it=graph[r].begin(); it!=graph[r].end(); ++it) {
		if(!dfn[*it]) {
			tarjan(*it);
			if (low[r]>low[*it])
				low[r]=low[*it];
		} else if (onstack[*it]&&dfn[*it]<low[r])
			low[r]=dfn[*it];
	}

	if (low[r]==dfn[r]) {
		int tn=0,st;
		do {
			st=stk.top();
			stk.pop();
			onstack[st]=false;
			++tn;
		} while(st!=r);
		ans+=tn*(tn-1)/2;
	}
}

int main() {
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF) {
		graph.resize(n+1);
		onstack.resize(n+1,false);
		dfn.resize(n+1,0);
		low.resize(n+1);

		int i,a,b;
		for (i=0; i<m; ++i) {
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
		}

		for (i=1; i<=n; ++i) {
			if (!dfn[i])
				tarjan(i);
		}

		printf("%d\n",ans);
	}
	return 0;
}
