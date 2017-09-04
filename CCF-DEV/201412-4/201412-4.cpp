/* 	其实这道题目就是求最小生成树的算法，与201609-4题一样的套路，ccf真没水平
	两种方法求最小生成树
	1.贪心算法
	2.并查集
*/
//解法一
#include<iostream>
#include<cstdio>
#include<vector>
#include<numeric>
using namespace std;
#define INF 0x3f3f3f3f

vector< vector< pair<int,int> > >graph;

int miniFare(int n) {
	vector<bool>visited(n+1,false);
	vector<int>dist(n+1,INF);
	dist[0]=dist[1]=0;

	int i,j,w,cur;
	for (i=0; i<n; ++i) {
		for (j=1,w=INF,cur=0; j<=n; ++j)
			if (!visited[j]&&dist[j]<w) {
				w=dist[j];
				cur=j;
			}
		visited[cur]=true;
		for (j=0; j<graph[cur].size(); ++j) {
			int tn=graph[cur][j].first;
			int tf=graph[cur][j].second;
			if (!visited[tn]&&tf<dist[tn])
				dist[tn]=tf;
		}
	}

	return accumulate(dist.begin(),dist.end(),0);
}

int main() {
	int m,n;
	while(scanf("%d %d",&n,&m)!=EOF) {
		graph.resize(n+1);
		int a,b,c;
		int i;
		for(i=0; i<m; ++i) {
			scanf("%d %d %d",&a,&b,&c);
			graph[a].push_back({b,c});
			graph[b].push_back({a,c});
		}
		printf("%d\n",miniFare(n));
	}
	return 0;
}

//解法二
#include<iostream>
#include<algorithm>
using namespace std;

int root[100000];    //记录麦田即对应点以及该点的根节点
struct Node {   //记录每个水渠的权值以及它的首尾节点
	int front;
	int next;
	int cost;
};

int findroot(int x) { //此函数用于找到每个节点的根节点
	int r = x;
	while(root[x] != x)
		x = root[x];  //如果该节点的父节点不是它本身，则把该节点的父节点赋值给它，直到找到了根节点
	while(r != root[x]) { //路径压缩
		root[r] = root[x];          //更新父亲为根
		r = root[r];                //移动到父亲节点
	}
	return x;     //返回根节点
}

bool cmp(Node x, Node y) { //针对价格的排序
	return x.cost < y.cost;
}

int main() {
	int n,m;
	cin >> n >> m;
	Node c[m];    //记录每一条水渠
	int sum(0),m1(m);
	for(int i = 0; i < n; i++)
		root[i] = i;    //将每一个节点的初始根节点设为其本身
	for(int i = 0; i < m; i++) {
		cin >> c[i].front >> c[i].next >> c[i].cost;
	}
	sort(c, c + m1, cmp);    //对价格进行升序排序
	for(int i = 0; i < m; i++) {
		if(findroot(c[i].front) != findroot(c[i].next)) {  //比较两节点的根节点是否相同
			sum += c[i].cost;
			//如果不相同，则把后者的根节点设为前者的根节点，即为集合的合并
			//这里如果两者的根节点一样，说明如果它们再相连会构成回路，说明该水渠不可取
			root[findroot(c[i].next)] = findroot(c[i].front);
		}
	}
	cout << sum <<endl;

	return 0;
}
