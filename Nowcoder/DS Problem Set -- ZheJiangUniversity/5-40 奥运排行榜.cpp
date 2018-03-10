#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include <stdio.h>
#include <math.h>

struct gold
{
	int nation;
	int n;
};

struct medal
{
	int nation;
	int n;
};
struct avrgold
{
	int nation;
    float n;
};
struct avrmedal
{
	int nation;
	float n;
};

int compare1(const void *p1, const void *p2)
{
	return ((struct gold*)p2)->n - ((struct gold*)p1)->n;
}
int compare2(const void *p1, const void *p2)
{
	return ((struct medal*)p2)->n - ((struct medal*)p1)->n;
}
int compare3(const void *p1, const void *p2)
{
	return ((struct avrgold*)p2)->n > ((struct avrgold*)p1)->n ? 1 : -1;
}
int compare4(const void *p1, const void *p2)
{
	return ((struct avrmedal*)p2)->n > ((struct avrmedal*)p1)->n ? 1 : -1;
}

void bestRank(struct gold *g, struct medal *m, struct avrgold *ag, struct avrmedal* am, int N, int nation,int *r, int *order)
{
	struct gold *pg = g;
	struct gold *qg = g + N - 1;

	for (; pg <= qg;++pg)
		if (pg->nation == nation)
		{
			int t = pg->n;
			for (--pg; t == pg->n; --pg)
				;

			*order = pg + 1 - g + 1;
			*r = 1;
			break;
		}

	struct medal *pm = m;
	struct medal *qm = m + N - 1;

	for (; pm <= qm; ++pm)
		if (pm->nation == nation)
		{
			int t = pm->n;
			for (--pm; t == pm->n; --pm)
				;

			int k = pm + 1 - m + 1;

			if (k < *order)
			{
				*order = k;
				*r = 2;
			}
			break;
		}

	struct avrgold *p1 = ag;
	struct avrgold *q1 = ag + N - 1;

	for (; p1 <= q1; ++p1)
		if (p1->nation == nation)
		{
			float t = p1->n;
			for (--p1; fabs(t - p1->n)<1e-6; --p1)
				;

			int k = p1 + 1 - ag + 1;
			if (k < *order)
			{
				*order = k;
				*r = 3;
			}
			break;
		}

	struct avrmedal *p2 = am;
	struct avrmedal *q2 = am + N - 1;

	for (; p2 <= q2; ++p2)
		if (p2->nation == nation)
		{
			float t = p2->n;
			for (--p2; fabs(t - p2->n)<1e-6; --p2)
				;

			int k = p2 + 1 - am + 1;
			if (k < *order)
			{
				*order = k;
				*r = 4;
			}
			break;
		}
}

int main()
{
	int N;
	int M;
	scanf("%d%d", &N, &M);

	struct gold *g = (struct gold*)malloc(N*sizeof(struct gold));
	struct medal *m = (struct medal*)malloc(N*sizeof(struct medal));
	struct avrgold *ag = (struct avrgold*)malloc(N*sizeof(struct avrgold));
	struct avrmedal* am = (struct avrmedal*)malloc(N*sizeof(struct avrmedal));

	int i;
	float people;
	for (i = 0; i < N; ++i)
	{
		scanf("%d%d%f", &g[i].n, &m[i].n, &people);
		g[i].nation = m[i].nation = ag[i].nation = am[i].nation = i;

		ag[i].n = g[i].n / people;
		am[i].n = m[i].n / people;
	}

	qsort(g, N, sizeof(struct gold), compare1);
	qsort(m, N, sizeof(struct medal), compare2);
	qsort(ag, N, sizeof(struct avrgold), compare3);
	qsort(am, N, sizeof(struct avrmedal), compare4);

	int notion;
	int order, rank;
	for (i = 0; i < M; ++i)
	{
		scanf("%d", &notion);
		bestRank(g, m, ag, am, N, notion, &rank, &order);
		if (i == 0)
			printf("%d:%d", order, rank);
		else
			printf(" %d:%d", order, rank);
	}

	return 0;
}