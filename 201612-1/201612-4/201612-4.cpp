#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct node {
	int charNum;
	int len;
};
#define NMAX 1000
int N[NMAX];
node dp[NMAX][NMAX];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(dp, 0, sizeof(dp));
		int i, j, k;
		int minij;
		for (i = 0; i < n; ++i)
			scanf("%d", N + i);

		for (j = 0; j < n; ++j) {
			dp[j][j] = { N[j] ,0 };
			for (i = j - 1; i >= 0; --i) {
				minij = 0x3f3f3f3f;
				for (k = i; k < j; ++k)
					minij = min(minij, dp[i][k].len + dp[i][k].charNum + dp[k + 1][j].len + dp[k + 1][j].charNum);
				dp[i][j] = { dp[i][j - 1].charNum + N[j],minij };
			}
		}

		/*for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j)
				printf("%2d|%2d ", dp[i][j].len,dp[i][j].charNum);
			printf("\n");
		}*/

		printf("%d\n", dp[0][n - 1].len);
	}
	return 0;
}