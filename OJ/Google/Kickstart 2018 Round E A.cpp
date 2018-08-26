#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
	int N, K;
	scanf("%d %d", &N, &K);
	priority_queue<int, vector<int>, greater<int>>Q;
	int i, A;
	for (i=0; i<N; ++i) {
		scanf("%d", &A);
		Q.push(A);
	}
	int ans=0;
	int day=0, leave=K;
	while(!Q.empty()) {
		int t=Q.top();
		Q.pop();
		if(leave<=0) {
			++day;
			leave=K;
		}
		if(day<t) {
			++ans;
			--leave;
		}
	}
	printf("%d\n", ans);
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout) ;

	int te;
	scanf("%d", &te);
	for (int w = 1; w <= te; w++) {
		cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}
