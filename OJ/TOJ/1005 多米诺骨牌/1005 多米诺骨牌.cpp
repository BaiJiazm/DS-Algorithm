#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=200000+10;
struct node {
	int p;
	int l;
};

int n,q;
int i,maxd,x,y;
node po[maxn];
int cost[maxn];

int main() {
	cin>>n;
	for(i=1; i<=n; ++i)
		//cin>>po[i].p>>po[i].l;
		scanf("%d %d",&po[i].p ,&po[i].l);
	cost[1]=0;
	maxd=po[1].p+po[1].l;
	for(i=2; i<=n; ++i) {
		if(maxd<po[i].p)
			cost[i]=cost[i-1]+po[i].p-maxd;
		else
			cost[i]=cost[i-1];
		maxd=max(maxd,po[i].l+po[i].p);
	}
	cin>>q;
	for(i=0; i<q; ++i) {
		//cin>>x>>y;
		scanf("%d %d",&x,&y);
		printf("%d\n",cost[y]-cost[x]);
		//cout<<cost[y]-cost[x]<<endl;
	}
	return 0;
}
