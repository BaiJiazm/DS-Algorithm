/*spfa算法求最短路径，允许负环 
 *有两种路，一种走完这条路需要的时间是正的，另一种需要的时间是负的，问有没
 *有这样一条回路，走完整条回路后，需要的时间的和是负的(判负环)
 *判断每个点的入队次数，如果大于N（图中总的点数），就是有负环
 *摘自  POJ 3259  虫洞 
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
struct node {
	int to;
	int len;
};

int F,N,M,W;
vector<vector<node> >graph;
//设置相应全局变量后，完全模板函数 
bool spfa(int s) {
	vector<int>dis(N+1,INF);
	dis[s]=0;
	vector<int>count(N+1,0);
	count[s]=1;
	vector<bool>inque(N+1,0);
	queue<int>q;
	q.push(s);

	while(!q.empty()) {
		int t=q.front();
		q.pop();
		inque[t]=false;
		for (int i=0; i<graph[t].size(); ++i) {
			node &nd=graph[t][i];
			if(dis[nd.to]>dis[t]+nd.len) {
				dis[nd.to]=dis[t]+nd.len;
				if (!inque[nd.to]) {
					inque[nd.to]=true;
					q.push(nd.to);
					if(++count[nd.to]>N)
						return false;
				}
			}
		}
	}
	return true;
}
int main() {
	cin>>F;
	while(cin>>N>>M>>W) {
		graph.assign(N+1,vector<node>());

		int s,e,t;
		int i;
		for(i=0; i<M; ++i) {
			cin>>s>>e>>t;
			graph[s].push_back({e,t});
			graph[e].push_back({s,t});
		}
		for (i=0; i<W; ++i) {
			cin>>s>>e>>t;
			graph[s].push_back({e,-t});
		}
		if(spfa(1))
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
