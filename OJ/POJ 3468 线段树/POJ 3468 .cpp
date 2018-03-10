#include<cstdio>
#include<iostream>
using namespace std;
#define NMAX 100005
struct node {
	int l,r;
	int mid() {
		return (l+r)>>1;
	}
};
node n[NMAX<<2];
long long sum[NMAX<<2];
long long lazy[NMAX<<2];

void build(int l,int r,int rt) {
	n[rt].l=l;
	n[rt].r=r;
	lazy[rt]=0;
	if (l==r) {
		scanf("%lld",sum+rt);
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	return ;
}

void pushDown(int rt) {
	if (lazy[rt]) {
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		int m=n[rt].mid();
		sum[rt<<1]+=(m-n[rt].l+1)*lazy[rt];
		sum[rt<<1|1]+=(n[rt].r-m)*lazy[rt];
		lazy[rt]=0;
	}
}

void update(int l,int r,int rt,int add) {
	if (l==n[rt].l&&r==n[rt].r) {
		sum[rt]+=(n[rt].r-n[rt].l+1)*add;
		lazy[rt]+=add;
		return ;
	}
	pushDown(rt);
	int m=n[rt].mid();
	if (r<=m)
		update(l,r,rt<<1,add);
	else if (l>m)
		update(l,r,rt<<1|1,add);
	else {
		update(l,m,rt<<1,add);
		update(m+1,r,rt<<1|1,add);
	}
	sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	return ;
}

long long query(int l,int r,int rt) {
	if (l==n[rt].l&&r==n[rt].r)
		return sum[rt];
	pushDown(rt);
	int m=n[rt].mid();
	if (r<=m)
		return query(l,r,rt<<1);
	else if(l>m)
		return query(l,r,rt<<1|1);
	else
		return  query(l,m,rt<<1)+query(m+1,r,rt<<1|1);
}
int main() {
	int N,Q;
	while(cin>>N>>Q) {
		build(1,N,1);
		int i,a,b,c;
		char ch[10];
		for (i=0; i<Q; ++i) {
			scanf("%s",ch);
			if (ch[0]=='C') {
				scanf("%d %d %d",&a,&b,&c);
				update(a,b,1,c);
			} else {
				scanf("%d %d",&a,&b);
				printf("%lld\n",query(a,b,1));
			}
		}
	}
	return 0;
}



#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

__int64 sum[N<<2],add[N<<2];
struct Node {
	int l,r;
	int mid() {
		return (l+r)>>1;
	}
} tree[N<<2];

void PushUp(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void PushDown(int rt,int m) {
	if(add[rt]) {
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * (m - (m>>1));
		sum[rt<<1|1] += add[rt] * (m>>1);
		add[rt] = 0;
	}
}

void build(int l,int r,int rt) {
	tree[rt].l = l;
	tree[rt].r = r;
	add[rt] = 0;
	if(l == r) {
		scanf("%I64d",&sum[rt]);
		return ;
	}
	int m = tree[rt].mid();
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int c,int l,int r,int rt) {
	if(tree[rt].l == l && r == tree[rt].r) {
		add[rt] += c;
		sum[rt] += (__int64)c * (r-l+1);
		return;
	}
	if(tree[rt].l == tree[rt].r) return;
	PushDown(rt,tree[rt].r - tree[rt].l + 1);
	int m = tree[rt].mid();
	if(r <= m) update(c,l,r,rt<<1);
	else if(l > m) update(c,l,r,rt<<1|1);
	else {
		update(c,l,m,rt<<1);
		update(c,m+1,r,rt<<1|1);
	}
	PushUp(rt);
}

__int64 query(int l,int r,int rt) {
	if(l == tree[rt].l && r == tree[rt].r) {
		return sum[rt];
	}
	PushDown(rt,tree[rt].r - tree[rt].l + 1);
	int m = tree[rt].mid();
	__int64 res = 0;
	if(r <= m) res += query(l,r,rt<<1);
	else if(l > m) res += query(l,r,rt<<1|1);
	else {
		res += query(l,m,rt<<1);
		res += query(m+1,r,rt<<1|1);
	}
	return res;
}

int main() {
	int n,m;
	while(~scanf("%d %d",&n,&m)) {
		build(1,n,1);
		while(m--) {
			char ch[2];
			scanf("%s",ch);
			int a,b,c;
			if(ch[0] == 'Q') {
				scanf("%d %d", &a,&b);
				printf("%I64d\n",query(a,b,1));
			}

			else {
				scanf("%d %d %d",&a,&b,&c);
				update(c,a,b,1);
			}
		}
	}
	return 0;
}
