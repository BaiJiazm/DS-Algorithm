#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N,M;
	while(cin>>N>>M) {
		vector<int>v(N);
		int cnt=0;
		int pre,post;
		int dist,dpre,dpost;
		int i,j;
		for(i=0; i<N; ++i) {
			cin>>v[i];
			cnt+=v[i];
		}
		if(cnt<M) {
			cout<<-1<<endl;
			continue;
		}
		for(i=0; v[i]; ++i)
			;
		v[i]=2;
		pre=i;
		post=i;
		dist=0;
		for(cnt=M-1, dis=0; cnt; --cnt) {
			for(; v[pre]; pre=(pre-1+N)%N)
				;
			for(; v[post]; post=(post+1+N)%N)
				;
			dpre=(i-pre+N)%N;
			dpost=(post-i+N)%N;
			if(dpre<=dpost) {
				dist+=dpre;
				v[pre]=3;
				--pre;
			}
		}
		int pf,po;
		int old,neww;
		for(old=i; old<N; ++old) {
			for(neww=old+1; neww<N&&v[neww]!=1; ++neww)
				;
			if(neww>=N)
				break;
			dist=(neww-old)
			     pf=pre;
			po=post;
			for(; v[pf]&&pf!=po; pf=(pf-1+N)%N)
				;

		}

	}
	return 0;
}

#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
int Getc[MAXN];
int Sum[MAXN];
int main() {
	//freopen("in.txt", "r", stdin);
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++) {
		scanf("%d", Getc + i);
	}
	int cnt = 0;
	for(int i = 1; i <= N; i++) {
		if(Getc[i] == 0) {
			a[cnt++] = i;
		}
	}
	for(int i = 0; i < cnt; i++) {
		a[cnt + i] = a[i] + N;
	}
	Sum[0] = a[0];
	for(int i = 1; i < cnt * 2; i++) {
		Sum[i] = Sum[i - 1] + a[i];
	}
	if(cnt < M) {
		printf("-1\n");
		return 0;
	}
	int ans = a[M / 2] * (M / 2) - Sum[M / 2 - 1] + Sum[M - 1] - Sum[M / 2] - (M - 1 - M / 2) * a[M / 2];
	for(int i = 1; i < cnt; i++) {
		ans = min(ans, a[(i + i + M) / 2] * (M / 2) - Sum[(i + i + M) / 2 - 1] + Sum[i - 1] + Sum[M + i - 1] - Sum[(i + i + M) / 2] - (M - 1 - M / 2) * a[(i + i + M) / 2]);
	}
	printf("%d\n", ans);
	return 0;
}

