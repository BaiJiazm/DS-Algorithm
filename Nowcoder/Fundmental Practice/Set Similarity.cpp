#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

#define NMAX 51

int main()
{
	set<int>s[51];
	int N, M, K;
	scanf("%d", &N);
	int i,t;
	for (i = 1; i <= N; ++i) {
		scanf("%d", &M);
		while (M--) {
			scanf("%d", &t);
			s[i].insert(t);
		}
	}
	int nc;
	scanf("%d", &K);
	while (K--) {
		int q1, q2;
		scanf("%d%d", &q1, &q2);
		nc = 0;
		for (set<int>::iterator iter = s[q1].begin();iter!=s[q1].end(); ++iter) {
			if (s[q2].find(*iter) != s[q2].end())
				++nc;
		}
		printf("%.1f%%\n", 100.0*nc / (s[q1].size() + s[q2].size() - nc));
	}
	return 0;
}