//#include<iostream>
//#include<vector>
//#include<cstring>
//using namespace std;
//const int maxn=20;
//
//int n,m;
//int vis[maxn];
//int can[maxn][4];
//vector<int>e[maxn];
//int ans=0;
//int nn=0;
//void init() {
//	memset(can,0,sizeof(can));
//	memset(vis,0,sizeof(vis));
//}
//void dfs(int u) {
//	++nn;
//	int i,j;
//	//cout<<u<<" "<<nn<<endl;
//	//getchar();
//	for(i=0; i<4; ++i)
//		if(can[u][i]==0) {
//			if(nn==n) {
//				++ans;
//				continue;
//			}
//			for(j=0; j<e[u].size(); ++j)
//				if (!vis[e[u][j]])
//					can[e[u][j]][i]++;
//			for(j=0; j<e[u].size(); ++j)
//				if (!vis[e[u][j]]) {
//					vis[e[u][j]]=1;
//					dfs(e[u][j]);
//					vis[e[u][j]]=0;
//				}
//			for(j=0; j<e[u].size(); ++j)
//				if (!vis[e[u][j]])
//					can[e[u][j]][i]--;
//		}
//	--nn;
//}
//
//int main() {
//	while(cin>>n>>m) {
//		init();
//		int u,v,i;
//		for(i=0; i<m; ++i) {
//			cin>>u>>v;
//			e[u].push_back(v);
//			e[v].push_back(u);
//		}
//		vis[1]=1;
//		dfs(1);
//		cout<<ans<<endl;
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=20;

int n,m;
int ans=0;
int can[maxn][4];
vector<int>e[maxn];
void init() {
	memset(can,0,sizeof(can));
}
void dfs(int u) {
	if(u==n+1){
		++ans;
		return ;
	}
	int i,j;
	for (i=0; i<4; ++i)
		if(!can[u][i]) {
			for(j=0; j<e[u].size(); ++j)
				if (e[u][j]>u)
					can[e[u][j]][i]++;
			dfs(u+1);
			for(j=0; j<e[u].size(); ++j)
				if (e[u][j]>u)
					--can[e[u][j]][i];
		}
}

int main() {
	while(cin>>n>>m) {
		init();
		int u,v,i;
		for(i=0; i<m; ++i) {
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
