#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f

class pairComp {
	public:
		bool operator () (const pair<int,int> &p1, const pair<int,int> &p2)const {
			return p1.second<p2.second;
		}
};

void Dijistra(vector< vector< pair<int,int> > >&graph,vector< vector< pair<int,int> > >&subGraph,int n,int start) {
	vector<bool>visited(n+1,false);
	vector<int> dis(n+1,INF);
		
	dis[start]=0;
	int w=INF;
	int cur;
	int i,j;
	for (i=0; i<n; ++i) {
		for (j=1,w=INF; j<=n; ++j)
			if (!visited[j]&&dis[j]<w) {
				w=dis[j];
				cur=j;
			}
		visited[cur]=true;
		int curDis=dis[cur];
		int size=graph[cur].size();
		for (j=0; j<size; ++j) {
			int np=graph[cur][j].first;
			int nw=graph[cur][j].second;
			if (!visited[np])
				if(curDis+nw<dis[np]) {
					subGraph[np].clear();
					subGraph[np].push_back({cur,nw});
					dis[np]=curDis+nw;
				} else if (curDis+nw==dis[np]) {
					subGraph[np].push_back({cur,nw});
				}
		}
	}
}

int mini(vector<int>&userD,vector< vector< pair<int,int> > >&subGraph,int n) {
	int cost=0;
	int start=userD.front();

	vector<bool>visited(n+1,false);
	visited[start]=true;

	int i,j;
	for (i=1; i<userD.size(); ++i) {
		int userd=userD[i];
		while(!visited[userd]) {
			pair<int,int >tp=*min_element(subGraph[userd].begin(),subGraph[userd].end(),pairComp());
			visited[userd]=true;
			cost+=tp.second;
			userd=tp.first;
		}
	}
	return cost;
}

int main() {
	freopen("test.txt","r",stdin);
	freopen("testOut.txt","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--) {
		int n,m,p;
		scanf("%d %d %d",&n,&m,&p);
		vector< vector< pair<int,int> > >graph(n+1);

		string str;
		vector<int>userD;
		cin>>str;
		for (int i=0; i<str.length(); ++i)
			if (str[i]=='1')
				userD.push_back(i+1);

		int u,v,w;
		for (int i=0; i<m; ++i) {
			scanf("%d %d %d",&u,&v,&w);
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}

		vector< vector< pair<int,int> > >subGraph(n+1);
		Dijistra(graph,subGraph,n,userD.front());
		printf("%d\n",mini(userD,subGraph,n));
	}
	return 0;
}
