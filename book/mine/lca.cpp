//��󹫹����ȣ�LCA��	�㷨���Ӷ�O��nlogn��

/*����һ���б�Ȩ�������ټ���һ���ߣ�Q��ѯ�ʣ�������֮�����̾��������˶���
 */
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=100005;
const int maxe=100005;
const int maxdep=20;

struct edge {
	int to;
	int w;		//��Ȩ��ʱ��ʡ��
	int next;
} e[maxn<<1];

int head[maxn],tot;
int dis[maxn];	//��Ȩ��ʱ��ʡ��
int dep[maxn];
int fa[maxn][maxdep];

void init() {
	tot=0;
	memset(head,-1,sizeof (head));
}
void addedge(int u,int v,int w) {
	e[tot].to=v;
	e[tot].w=w;	//��ʡ��
	e[tot].next=head[u];
	head[u]=tot++;
}
void dfs(int u,int pre,int d) {
	dep[u]=d;
	fa[u][0]=pre;
	for (int i=1; i<maxdep; ++i)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for (int i=head[u]; i!=-1; i=e[i].next) {
		int v=e[i].to;
		if (v==pre)
			continue;
		dis[v]=dis[u]+e[i].w;	//��ʡ��
		dfs(v,u,d+1);
	}
}
/*��ȫģ�庯��
  ����u��v�����ڵ�� LCA
 */
int lca(int u,int v) {
	if (dep[u]>dep[v])
		swap(u,v);
	int hu=dep[u],hv=dep[v];
	int tu=u,tv=v;
			//��v�ڵ���ǰ��det����
	for (int det=hv-hu,i=0; det; det>>=1,i++)
		if(det&1)
			tv=fa[tv][i];
	if (tu==tv)
		return tu;
			//�𲽱ƽ�tv,tu��LCA
	for (int i=maxdep-1; i>=0; --i) {
		if (fa[tu][i]==fa[tv][i])
			continue;
		tu=fa[tu][i];
		tv=fa[tv][i];
	}
	return fa[tu][0];
}

int main() {
	int T,N,Q;
	scanf("%d",&T);
	for (int t=1; t<=T; ++t) {
		scanf("%d %d",&N,&Q);
		init();
		int i, u,v,w;
		for (i=1; i<N; ++i) {
			scanf("%d %d %d",&u,&v,&w);
			addedge(u,v,w);
			addedge(v,u,w);
		}
		scanf("%d %d %d",&u,&v,&w);
		dis[1]=0;
		dfs(1,1,0);
		printf("Case #%d:\n",t);
		while(Q--) {
			int a,b;
			scanf("%d %d",&a,&b);
			int L1=dis[a]+dis[b]-2*dis[lca(a,b)];
			int L2=dis[a]+dis[u]-2*dis[lca(a,u)]+dis[b]+dis[v]-2*dis[lca(b,v)]+w;
			int L3=dis[a]+dis[v]-2*dis[lca(a,v)]+dis[b]+dis[u]-2*dis[lca(b,u)]+w;
			printf("%d\n",L1-min(L1,min(L2,L3)));
		}
	}
	return 0;
}