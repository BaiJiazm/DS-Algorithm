//个人错误解法，ac 70%
//#include <bits/stdc++.h>
//using namespace std;
//
//const int N=1e6+5;
//bool b[N];
//vector<int>p;
//
//void prime(int n) {
//	memset(b, 0, sizeof(b));
//	int i, j;
//	p.push_back(1);
//	for(i=2; i<n; ++i) {
//		if(!b[i]) {
//			p.push_back(i);
//			for(j=i+i; j<n; j+=i)
//				b[j]=true;
//		}
//	}
//}
//
//int main() {
//	prime(N);
//
//	int n;
//	while(~scanf("%d", &n)) {
//		int ans=*(upper_bound(p.begin(), p.end(), n)-1);
//		printf("%d\n", ans*2);
//	}
//	return 0;
//}

//正确解法
//https://blog.csdn.net/f_zyj/article/details/52579219
#include <stdio.h>

#define MAXN 1000009
#define MAXP 300000
#define max(a, b) ((a) > (b) ? (a) : (b))

int prime[MAXN];
int p[MAXP];

int main() {
	int k = 0;
	for (int i = 2; i < MAXN; i++) {
		if (!prime[i]) {
			p[k++] = i;
			for (int j = 2 * i; j < MAXN; j += i) {
				prime[j] = 1;
			}
		}
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		int N, g = 1;
		scanf("%d", &N);
		for (int i = 0; p[i] <= N; i++) {
			for (int j = p[i]; j <= N; j *= p[i]) {
				g = max(g, j);
			}
		}
		printf("%d\n", g * 2);
	}
	return 0;
}
