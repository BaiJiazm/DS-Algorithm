#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
using namespace std;

#define NMAX 1000
int main()
{
	//freopen("test1.txt", "r", stdin);
	int n[NMAX + 1];
	int N;
	while (scanf("%d", &N) != EOF) {
		int i;
		for (i = 1; i <= N; ++i)
			scanf("%d", n + i);
		sort(n + 1, n + N + 1);

		int ans = -1;
		int mid = n[(N + 1) / 2];
		int count = 0;
		for (i = (N + 1) / 2; i && n[i] == mid; --i)
			++count;
		for (i = (N + 1) / 2 + 1; i <= N && n[i] == mid; ++i)
			++count;
		if (count % 2 == N % 2)
			ans = mid;
		printf("%d\n", ans);
	}
	return 0;
}