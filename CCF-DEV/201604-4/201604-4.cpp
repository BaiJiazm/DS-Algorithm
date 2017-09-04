#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define NMAX 100
#define MMAX 100

struct node {
	int start;
	int end;
};

int main()
{
	//freopen("test4.txt","r",stdin);
	//freopen("testOut.txt","w",stdout);

	int n, m, t;
	while (scanf("%d %d %d", &n, &m, &t) != EOF) {
		struct node error[NMAX + 2][MMAX + 2];
		memset(error, -1, sizeof(error));

		int i, j;
		int maxb = -1;
		int r, c, a, b;
		for (i = 0; i < t; ++i) {
			scanf("%d %d %d %d", &r, &c, &a, &b);
			error[r][c] = { a,b };
			maxb = max(maxb, b);
		}

		bool cur[NMAX + 2][MMAX + 2];
		bool next[NMAX + 2][MMAX + 2];
		memset(cur, 0, sizeof(cur));
		memset(next, 0, sizeof(next));

		bool(*pcur)[MMAX + 2];
		bool(*pnext)[MMAX + 2];
		bool(*pt)[MMAX + 2];
		pcur = cur;
		pnext = next;
		cur[1][1] = true;

		int time;
		if (n == 1 && m == 1 || maxb <= 0) {
			time = n - 1 + m - 1;
		}
		else {
			for (time = 1; time <= maxb; ++time) {
				for (i = 1; i <= n; ++i)
					for (j = 1; j <= m; ++j) {
						struct node& nod = error[i][j];
						if (time >= nod.start&&time <= nod.end)
							pnext[i][j] = false;
						else
							pnext[i][j] = pcur[i][j - 1] || pcur[i][j + 1] || pcur[i - 1][j] || pcur[i + 1][j];
					}
				if (pnext[n][m])
					break;

				pt = pcur;
				pcur = pnext;
				pnext = pt;
			}
			if (time > maxb) {
				int leave = NMAX + MMAX;
				for (i = 1; i <= n; ++i)
					for (j = 1; j <= m; ++j)
						if (pcur[i][j])
							leave = min(leave, n - i + m - j);
				time += leave - 1;
			}
		}
		printf("%d\n", time);

	}
	return 0;
}

