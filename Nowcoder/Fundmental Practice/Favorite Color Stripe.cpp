#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define NMAX 200
#define LMAX 10000

int n[NMAX + 1];
int l[LMAX + 1];
int LL[NMAX + 1][LMAX + 1];
int N, L;
int totalColor;

int dp()
{
	int i, j;
	for (i = 0; i <= N; ++i)
		LL[i][0] = 0;
	for (j = 0; j <= L; ++j)
		LL[0][j] = 0;

	int len;
	for (i = 1; i <= N; ++i)
		for (j = 1; j <= L; ++j) {
			len = max(LL[i - 1][j], LL[i][j - 1]);
			LL[i][j] = n[i] == l[j] ? len + 1 : len;
		}
	return LL[N][L];
}

int main()
{
	while (scanf("%d", &totalColor) != EOF) {
		int i;
		scanf("%d", &N);
		for (i = 1; i <= N; ++i)
			scanf("%d", n + i);
		scanf("%d", &L);
		for (i = 1; i <= L; ++i)
			scanf("%d", l + i);
		
		printf("%d\n", dp());
	}
	return 0;
}