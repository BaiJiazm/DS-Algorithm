#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define M 100
#define N 100

int m, n, q;
char ch[N + 2][M + 2];
char chch;

struct node {
	int x, y;
};
void fun0()
{
	int x1, y1, x2, y2;
	int pos1, pos2;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	if (x1 == x2) {
		pos1 = min(y1, y2);
		pos2 = max(y1, y2);
		for (; pos1 <= pos2; ++pos1)
			if (ch[n - pos1][x1 + 1] != '+')
				ch[n - pos1][x1 + 1] = ch[n - pos1][x1 + 1] == '-' ? '+' : '|';
	}
	else {
		pos1 = min(x1, x2);
		pos2 = max(x1, x2);
		for (; pos1 <= pos2; ++pos1)
			if (ch[n - y1][pos1 + 1] != '+')
				ch[n - y1][pos1 + 1] = ch[n - y1][pos1 + 1] == '|' ? '+' : '-';
	}
}
void fun1(int x, int y)
{
	stack<node>s;
	s.push({ x, y });
	char tch;
	while (!s.empty()) {
		x = s.top().x;
		y = s.top().y;
		s.pop();
		tch = ch[x][y];
		if (tch != '-'&&tch != '|'&&tch != '+'&&tch != chch) {
			ch[x][y] = chch;
			s.push({ x - 1,y });
			s.push({ x + 1,y });
			s.push({ x ,y - 1 });
			s.push({ x ,y + 1 });
		}
	}
}

int main()
{
	//freopen("test.txt", "r", stdin);
	//freopen("testOut.txt", "w", stdout);

	int i, j;
	int x, y;
	while (scanf("%d %d %d", &m, &n, &q) != EOF) {
		for (i = 0; i <= n + 1; ++i)
			for (j = 0; j <= m + 1; ++j)
				ch[i][j] = i == 0 || i == n + 1 || j == 0 || j == m + 1 ? '-' : '.';
		for (i = q; i--;) {
			scanf("%d", &j);
			if (!j)
				fun0();
			else {
				scanf("%d %d %c", &x, &y, &chch);
				fun1(n - y, x + 1);
			}
		}
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= m; ++j)
				printf("%c", ch[i][j]);
			printf("\n");
		}
	}
	return 0;
}