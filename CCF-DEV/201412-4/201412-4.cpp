/* 	��ʵ�����Ŀ��������С���������㷨����201609-4��һ������·��ccf��ûˮƽ
	���ַ�������С������
	1.̰���㷨
	2.���鼯
*/
//�ⷨһ
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

//�ⷨ��
#include<iostream>
#include<algorithm>
using namespace std;

int root[100000];    //��¼���Ｔ��Ӧ���Լ��õ�ĸ��ڵ�
struct Node {   //��¼ÿ��ˮ����Ȩֵ�Լ�������β�ڵ�
	int front;
	int next;
	int cost;
};

int findroot(int x) { //�˺��������ҵ�ÿ���ڵ�ĸ��ڵ�
	int r = x;
	while(root[x] != x)
		x = root[x];  //����ýڵ�ĸ��ڵ㲻����������Ѹýڵ�ĸ��ڵ㸳ֵ������ֱ���ҵ��˸��ڵ�
	while(r != root[x]) { //·��ѹ��
		root[r] = root[x];          //���¸���Ϊ��
		r = root[r];                //�ƶ������׽ڵ�
	}
	return x;     //���ظ��ڵ�
}

bool cmp(Node x, Node y) { //��Լ۸������
	return x.cost < y.cost;
}

int main() {
	int n,m;
	cin >> n >> m;
	Node c[m];    //��¼ÿһ��ˮ��
	int sum(0),m1(m);
	for(int i = 0; i < n; i++)
		root[i] = i;    //��ÿһ���ڵ�ĳ�ʼ���ڵ���Ϊ�䱾��
	for(int i = 0; i < m; i++) {
		cin >> c[i].front >> c[i].next >> c[i].cost;
	}
	sort(c, c + m1, cmp);    //�Լ۸������������
	for(int i = 0; i < m; i++) {
		if(findroot(c[i].front) != findroot(c[i].next)) {  //�Ƚ����ڵ�ĸ��ڵ��Ƿ���ͬ
			sum += c[i].cost;
			//�������ͬ����Ѻ��ߵĸ��ڵ���Ϊǰ�ߵĸ��ڵ㣬��Ϊ���ϵĺϲ�
			//����������ߵĸ��ڵ�һ����˵����������������ṹ�ɻ�·��˵����ˮ������ȡ
			root[findroot(c[i].next)] = findroot(c[i].front);
		}
	}
	cout << sum <<endl;

	return 0;
}
