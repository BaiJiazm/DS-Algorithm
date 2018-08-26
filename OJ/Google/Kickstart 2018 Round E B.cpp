#include<bits/stdc++.h>
using namespace std;

#define MAXP 105
#define MAX_ROW 10005
#define INF 0x3f3f0000

int v1[MAXP];
int dp[MAX_ROW][MAXP];
unordered_set<string> st;
int N, M, P;
char str[MAXP];

bool check(int i, int j) {
	if(j<0) {
		return st.count(str)==0;
	}

	if(dp[i][j]&1) {
		str[j]='0';
		if(check(i-v1[j], j-1)) {
			return true;
		}
	}
	if(dp[i][j]&2) {
		str[j]='1';
		if(check(i-N+v1[j], j-1)) {
			return true;
		}
	}
	return false;
}

void solve() {
	scanf("%d %d %d", &N, &M, &P);
	memset(v1, 0, sizeof(v1));
	memset(dp, 0, sizeof(dp));

	int i, j;
	for (int i=0; i<N; ++i) {
		scanf("%s", str);
		for (j=0; j<P; ++j) {
			v1[j]+=str[j]=='1';
		}
	}
	st.clear();
	for (int i=0; i<M; ++i) {
		scanf("%s", str);
		st.insert(str);
	}

	int maxRow=P*N;
	dp[v1[0]][0]|=1;
	dp[N-v1[0]][0]|=2;
	for (j=1; j<P; ++j) {
		for (i=0; i<=maxRow; ++i) {
			if(dp[i][j-1]) {
				if(i+v1[j]<=maxRow) {
					dp[i+v1[j]][j]|=1;
				}
				if(i+N-v1[j]<=maxRow) {
					dp[i+N-v1[j]][j]|=2;
				}
			}
		}
	}

//	for (i=0; i<=maxRow; ++i){
//		for (j=0; j<P; ++j){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	
	for(i=0; i<=maxRow; ++i) {
		if(dp[i][P-1]) {
			if(check(i, P-1)) {
				printf("%d\n", i);
				return ;
			}
		}
	}
//	cout<<"None\n";
}

int main() {
	freopen("B-large-practice.in", "r", stdin);
	freopen("B.out", "w", stdout) ;

	int te;
	scanf("%d", &te);
	for (int w = 1; w <= te; w++) {
		cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}
