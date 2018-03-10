#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int N;
	int a,b;
	int i;
	while(cin>>N) {
		vector<vector<int>>g(N+1);
		vector<int>edges(N+1,0);
		for(i=1; i<N; ++i) {
			scanf("%d %d",&a,&b);
			g[a].push_back(b);
			g[b].push_back(a);
			++edges[a];
			++edges[b];
		}
		int ans=0;
		stack<int>s;
		vector<int>n(N+1,1);
		for(i=1; i<=N; ++i) {
			if(edges[i]==1)
				s.push(i);
		}
		
		int adj;
		while(!s.empty()) {
			int top=s.top();
			s.pop();
			for(int i=0;i<g[top].size();++i)
				if(edges[g[top][i]]){
					adj=g[top][i];
					break;
				}
			g[top].clear();
			edges[top]=0;

			if(n[top]%2==0) {
				ans++;
			} else {
				n[adj]+=n[top];
			}
			if(--edges[adj]==1)
				s.push(adj);
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
