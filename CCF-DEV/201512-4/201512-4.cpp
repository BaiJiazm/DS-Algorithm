//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//vector<vector<int> >graph;
//vector<int>pv;
//vector<int>ans;
//
//void dfs() {
//	int pn=1;
//	while(1) {
//		ans.push_back(pn);
//		int i;
//		for ( i=pv[pn]; i<graph[pn].size()&&!graph[pn][i]; ++i)
//			;
//		if (i==graph[pn].size())
//			return ;
//		else {
//			int next=graph[pn][i];
//			graph[pn][i]=0;
//			++pv[pn];
//			for (int j=pv[next]; j<graph[next].size(); ++j)
//				if (graph[next][j]==pn) {
//					graph[next][j]=0;
//					break;
//				}
//			pn=next;
//		}
//	}
//}
//
//int main() {
//	int m,n;
//	while(scanf("%d %d",&n,&m)) {
//		graph.resize(n+1);
//		pv.resize(n+1,0);
//
//		int i,a,b;
//		for (int i=0; i<m; ++i) {
//			scanf("%d %d",&a,&b);
//			graph[a].push_back(b);
//			graph[b].push_back(a);
//		}
//
//		for (int j=0;j<graph.size();++j)
//			sort(graph[j].begin(),graph[j].end());
//
//		dfs();
//
//		if (ans.size()==m+1) {
//			for (int j=0; j<=m; ++j)
//				j?printf(" %d",ans[j]):printf("%d",ans[j]);
//			printf("\n");
//		} else
//			printf("-1\n");
//	}
//	return 0;
//}


#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

#define NMAX 10001
bool visited[NMAX][NMAX];

vector<vector<int> >graph(NMAX);
vector<int>pv;
vector<int>ans;

//void dfs() {
//	int pn=1;
//	while(1) {
//		ans.push_back(pn);
//		int i=pv[pn];
//		int size=graph[pn].size();
//		for ( ; i<size&&visit[pn][graph[pn][i]]; ++i)
//			;
//		if (i==size)
//			return ;
//		else {
//			int next=graph[pn][i];
//			visit[pn][next]=true;
//			visit[next][pn]=true;
//			++pv[pn];
//			pn=next;
//		}
//	}
//}
void euler(int u) {
	vector<int>::iterator pos;
	//����dfs�ķ����������еı�
	for(pos=graph[u].begin(); pos!=graph[u].end(); pos++) {
		long int v=*pos;
		if(!visited[u][v]) {
			visited[u][v]=visited[v][u]=1;
			ans.push_back(v);
			euler(v);
		}
	}
}

bool vis[NMAX];
void dfs(int u) {
	vis[u]=true;
	vector<int>::iterator pos;
	for(pos=graph[u].begin(); pos!=graph[u].end(); pos++) {
		int v=*pos;
		if(!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	int m,n;
	while(scanf("%d %d",&n,&m)) {
		//memset(visited,false,sizeof (visited));
		//graph.resize(n+1);
		//	pv.resize(n+1,0);

		long long int d[NMAX];

		int i,a,b;
		for (int i=0; i<m; ++i) {
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
			graph[b].push_back(a);
			++d[a];
			++d[b];
		}

//		for (int j=0; j<graph.size(); ++j)
//			sort(graph[j].begin(),graph[j].end());

//		dfs(1);
//		bool flag=0;
//		for(int i=1; i<=n; i++)
//			if(vis[i]==0) {
//				flag=1;
//				break;
//			}
//		if (flag) {
//			printf("-1");
//			continue;
//		}
//
//		long long int odd_num=0;
//		for(long int i=1; i<=n; i++) {
//			sort(graph[i].begin(),graph[i].end());
//			if(d[i]%2)
//				odd_num++;
//		}
//		if(odd_num>2){
//			printf("-1");
//			continue;
//		}

		ans.push_back(1);
		euler(1);


		if (ans.size()==m+1) {
			for (int j=0; j<=m; ++j)
				j?printf(" %d",ans[j]):printf("%d",ans[j]);
			printf("\n");
		} else
			printf("-1\n");
	}
	return 0;
}










//  ����⣬˼·�ǳ��򵥣����ǵ�ĿǰΪֹ������û��ac��Ϊʲô�ᳬʱ��������Ͳ��᣿

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define N 10010
using namespace std;

vector<long int> head[N];
stack<long int> way;
long int n;
bool visited[N][N];
bool vis[N];
long long int d[N];

void addEdge(long int x,long int y) {
	head[x].push_back(y);
	head[y].push_back(x);
	d[x]++;
	d[y]++;
}

void dfs(int u) {
	vis[u]=1;
	vector<long int>::iterator pos;
	for(pos=head[u].begin(); pos!=head[u].end(); pos++) {
		long int v=*pos;
		if(!vis[v]) {
			dfs(v);
		}
	}

}

void euler(long int u) {
	vector<long int>::iterator pos;
	//����dfs�ķ����������еı�
	for(pos=head[u].begin(); pos!=head[u].end(); pos++) {
		long int v=*pos;
		if(!visited[u][v]) {
			visited[u][v]=visited[v][u]=1;
			//�����ﲻ��ջ�������ڽ�����һ����֮ǰ�Ͱѵ�ǰ������������ǹ��ˣ����ǽ���ȥֻ�ܵ�10��
			//cout<<' '<<v;
			euler(v);
			//��ջ�Ļ���û���⣬���Ե�90�֡�
			way.push(v);
		}
	}
}

int main() {
	long long int m;
	cin>>n>>m ;
	while(m--) {
		long int x,y;
		cin>>x>>y;
		addEdge(x,y);
	}
	//��ǰ���ǵ�90�ֵ�ԭ�����û�п���ͼ����ͨ�����
	//����ӵ�һ�������dfs���еĵ㣬�����鼴��
	dfs(1);
	bool flag=0;
	for(int i=1; i<=n; i++)
		if(vis[i]==0) {
			flag=1;
			break;
		}
	//����ǲ���ͨ�ģ�ֱ�����-1
	if(flag==1) cout<<-1;
	else {
		long long int odd_num=0;
		for(long int i=1; i<=n; i++) {
			sort(head[i].begin(),head[i].end());
			if(d[i]%2)
				odd_num++;
		}
		if(odd_num>2)
			cout<<-1;
		else {
			cout<<1;
			euler(1);
			while(!way.empty()) {
				cout<<' '<<way.top();
				way.pop();
			}
		}
	}



	return 0;
}
