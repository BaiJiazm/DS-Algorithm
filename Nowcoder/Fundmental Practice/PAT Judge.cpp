#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define KMAX 5

struct user {
	int no;
	int score[KMAX+1];
	int perfectNum;
};

bool cmp(const user&u1, const user&u2)
{
	return u1.score[0] > u2.score[0] || (u1.score[0] == u2.score[0] && (u1.perfectNum > u2.perfectNum || u1.perfectNum == u2.perfectNum&&u1.no < u2.no));
}
int main()
{
	//freopen("dataIn.txt", "r", stdin);
	//freopen("dataOut.txt", "w",stdout);

	int N, K, M;
	struct user *U;
	int full[KMAX + 1];

	while (scanf("%d %d %d", &N, &K, &M) != EOF) {
		U = (struct user *)malloc(sizeof(struct user)*(N + 1));

		int i, add;
		int u, t, s;
		for (i = 1; i <= N; ++i) {
			U[i].no = i;
			memset(U[i].score, -1, sizeof(U[i].score));
			U[i].perfectNum = 0;
		}

		for (i = 1; i <= K; ++i)
			scanf("%d", full + i);
		for (i = 1; i <= M; ++i) {
			scanf("%d %d %d", &u, &t, &s);
			
			int ori = U[u].score[t];
			if (ori == -1 && s == -1)
				U[u].score[t] = 0;
			else if (ori <= s) {
				U[u].score[t] = s;
				add = ori == -1 ? s : s - ori;
				U[u].score[0] += U[u].score[0] == -1 ? add + 1 : add;
				if (ori!=s&&s == full[t])
					U[u].perfectNum++;
			}
		}
		sort(U + 1, U + N + 1, cmp);

		int r;
		for (i = 1,r=1; i <= N;++i)
			if (U[i].score[0] >= 0) {
				if (U[i].score[0] != U[i - 1].score[0])
					r = i;
				printf("%d %05d", r, U[i].no);
				for (int j = 0; j <= K; ++j)
					U[i].score[j] >= 0 ? printf(" %d", U[i].score[j]) : printf(" -");
				printf("\n");
			}
	}
	return 0;
}