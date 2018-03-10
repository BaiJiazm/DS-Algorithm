#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

#define NMAX 100
struct node {
	int order;
	int value;
};

int m[NMAX][2];
struct node dat[NMAX];

void levelOut()
{
	queue<int>q;
	int t;
	q.push(0);

	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t == 0)
			printf("%d", dat[0].value);
		else
			printf(" %d", dat[t].value);
		
		if (m[t][0] != -1)
			q.push(m[t][0]);
		if (m[t][1] != -1)
			q.push(m[t][1]);
	}
}
int ord = 0;
void orderOut(int rt)
{
	if (rt == -1)
		return;
	orderOut(m[rt][0]);
	dat[ord++].order = rt;
	orderOut(m[rt][1]);
}

int compare1(const void *p1, const void *p2)
{
	return (*(struct node *)p1).value - (*(struct node *)p2).value;
}

int compare2(const void *p1, const void *p2)
{
	return (*(struct node *)p1).order - (*(struct node *)p2).order;
}

int main()
{
	int N;
	scanf("%d", &N);

	int i;
	for (i = 0; i < N; ++i)
		scanf("%d%d", &m[i][0], &m[i][1]);
	for (i = 0; i < N; ++i)
		scanf("%d", &dat[i].value);

	qsort(dat, N, sizeof(struct node), compare1);
	orderOut(0);
	qsort(dat, N, sizeof(struct node), compare2);
	levelOut();
}