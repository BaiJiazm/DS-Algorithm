#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define NMAX 40000
#define MMAX 100
#define KMAX 5

struct stu
{
	int ge;
	int gei;
	int no;
};

struct stu s[NMAX];
int choice[NMAX][KMAX];
int squota[MMAX];
int N, M, K;
vector<vector<stu>>rs;

int compare(const void *p1,const void *p2)
{
	int r = ((struct stu *)p2)->gei - ((struct stu*)p1)->gei;
	if (r == 0)
		r = ((struct stu *)p2)->ge - ((struct stu*)p1)->ge;
	if (r == 0)
		r = ((struct stu *)p1)->no - ((struct stu*)p2)->no;
	return r;
}

bool compare1(const stu &v1, const stu &v2)
{
	return v1.no < v2.no ? true : false;
}
void admit()
{
	int i, j;
	int choose;
	for (i = 0; i < N; ++i)
		for (j = 0; j < K; ++j)
		{
			choose = choice[s[i].no][j];
			if (squota[choose] > rs[choose].size())
			{
				rs[choose].push_back(s[i]);
				break;
			}
			else
			{
				struct stu t = rs[choose].back();
				if (i&&t.gei == s[i].gei&&t.ge == s[i].ge)
				{
					rs[choose].push_back(s[i]);
					break;
				}
			}
		}
}
int main()
{
	scanf("%d%d%d", &N, &M, &K);
	int i, j, ge, gi;
	for (i = 0; i < M; ++i)
		scanf("%d", squota + i);
	for (i = 0; i < N; ++i)
	{
		scanf("%d%d", &ge, &gi);
		s[i].gei = ge + gi;
		s[i].ge = ge;
		s[i].no = i;
		for (j = 0; j < K; ++j)
			scanf("%d", choice[i] + j);
	}
	qsort(s, N, sizeof(struct stu), compare);

	rs.resize(M);
	admit();

	for (i = 0; i < M; ++i)
	{
		sort(rs[i].begin(), rs[i].end(), compare1);
		for (j = 0; j < rs[i].size(); ++j)
			if (j)
				printf(" %d", rs[i][j].no);
			else
				printf("%d", rs[i][0].no);
		printf("\n");
	}

	return 0;
}