#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f

class edge{
public:
	int mi;
	int ma;
	int dist;
	edge(int f,int t,int d){
		mi=f;
		ma=t;
		dist=d;
	}
	bool operator <(const edge &e)const {
		return dist<e.dist;
	}
};

vector<edge> edges;
vector<int>fa;
vector<int>cost;

int findFather(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=findFather(fa[x]);
}

int main(){
	int n,m;
	while(cin>>n>>m){
		edges.clear();
		fa.resize(n+1);
		cost.resize(n+1,INF);
		int a,b,c;
		int i;
		for(i=0;i<m;++i){
			cin>>a>>b>>c;
			edges.push_back(edge(min(a,b), max(a,b), c));
		}
		sort(edges.begin(),edges.end());
		for(i=0;i<n+1;++i)
			fa[i]=i;
		int ans=0;
		for(i=0;i<m;++i){
			int mif=findFather(edges[i].mi);
			int maf=findFather(edges[i].ma);
			int newf=min(fa[mif],fa[maf]);
			fa[mif]=newf;
			fa[maf]=newf;
			if(findFather(n)==1){
				ans=edges[i].dist;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
