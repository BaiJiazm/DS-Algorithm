#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
//	char no[7];
	int no;
	char name[9];
	int score;
};

typedef struct student SortType;

int compare1(void *p1, void *p2)
{
	SortType *e1 = (SortType*)p1;
	SortType *e2 = (SortType*)p2;

	//return strcmp(e1->no, e2->no);
	return e1->no - e2->no;
}

int compare2(void *p1, void *p2)
{
	SortType *e1 = (SortType*)p1;
	SortType *e2 = (SortType*)p2;

	int r = strcmp(e1->name, e2->name);
	if (r == 0)
//		return strcmp(e1->no, e2->no);
        return e1->no - e2->no;

	return r;
}

int compare3(void *p1, void *p2)
{
	SortType *e1 = (SortType*)p1;
	SortType *e2 = (SortType*)p2;

	int r = e1->score - e2->score;
	if (r == 0)
		//return strcmp(e1->no, e2->no);
		return e1->no - e2->no;

	return r;
}

int Partition(SortType *n, int low, int high,int (*compare)(void *,void *))
{
	SortType t = n[low];
	SortType pivotkey = n[low];

	while (low < high)
	{
		while (low < high&&compare(n + high, &pivotkey) >= 0)
			high--;
		n[low] = n[high];
		while (low < high&&compare(n + low, &pivotkey) <= 0)
			low++;
		n[high] = n[low];
	}
	n[low] = t;
	return low;
}

void QuickSort(SortType *n, int low, int high, int(*compare)(void *, void *))
{
	int pivotloc = low;
	if (low < high)
	{
		pivotloc = Partition(n, low, high, compare);
		QuickSort(n, low, pivotloc - 1, compare);
		QuickSort(n, pivotloc + 1, high, compare);
	}
}

int main()
{
	int N, C;
	int i;

	scanf("%d", &N);
	scanf("%d", &C);
	struct student *S = (struct student*)malloc(N*sizeof(struct student));

	for (i = 0; i < N; ++i)
		scanf("%d%s%d", &S[i].no, S[i].name, &S[i].score);

	int(*pfun)(void*, void *);
	if (C == 1)
		pfun = compare1;
	else if (C == 2)
		pfun = compare2;
	else
		pfun = compare3;

	QuickSort(S, 0, N - 1, pfun);

	for (i = 0; i < N; ++i)
	{
		printf("%06d ", S[i].no);
		printf("%s ", S[i].name);
		printf("%d\n", S[i].score);
	}
	return 0;
}


#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node {
	char name[10];
	int id, score;
}lst[100005];
bool cmp1(const node& a, const node& b) {
	return a.id < b.id;
}
bool cmp2(const node& a, const node& b) {
	int t = strcmp(a.name, b.name);
	if (t == 0) return a.id < b.id;
	return 0 > t;
}
bool cmp3(const node& a, const node& b) {
	if (a.score == b.score) return a.id < b.id;
	return a.score < b.score;
}
int main()
{
	int n, k;
	char name[10];
	int id, score;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%s%d", &lst[i].id, lst[i].name, &lst[i].score);
	}
	if (k == 1) sort(lst, lst + n, cmp1);
	if (k == 2) sort(lst, lst + n, cmp2);
	if (k == 3) sort(lst, lst + n, cmp3);
	for (int i = 0; i < n; ++i) {
		printf("%06d %s %d\n", lst[i].id, lst[i].name, lst[i].score);
	}
	return 0;
}