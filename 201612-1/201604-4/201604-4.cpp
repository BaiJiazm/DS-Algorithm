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


//方法二：广度优先搜索		时间空间都不如第一种方法
/* 
#include<stdio.h>
#include<queue>
using namespace std;
typedef struct
{
int x, y;
int t;
}State;
typedef struct
{
int l;
int r;
}Dead;
Dead s[105][105] = {0};
State temp, now;
int flag[105][105][305] = {0}, dir[4][2] = {0,1,0,-1,1,0,-1,0};
queue<State> q;
int main(void)
{
int i, n, m, t, x, y, l, r;
scanf("%d%d%d", &n, &m, &t);
for(i=1;i<=t;i++)
{
scanf("%d%d%d%d", &x, &y, &l, &r);
s[x][y].l = l, s[x][y].r = r;
}
now.x = now.y = 1, now.t = 0;
q.push(now);
while(q.empty()==0)
{
now = q.front();
q.pop();
if(now.x==n && now.y==m)
break;
t = temp.t = now.t+1;
for(i=0;i<=3;i++)
{
x = temp.x = now.x+dir[i][0];
y = temp.y = now.y+dir[i][1];
if(x>=1 && y>=1 && x<=n && y<=m && (t<s[x][y].l || t>s[x][y].r) && t<=300 && flag[x][y][t]==0)
q.push(temp), flag[x][y][t] = 1;
}
}
printf("%d\n", now.t);
return 0;
}

*/
