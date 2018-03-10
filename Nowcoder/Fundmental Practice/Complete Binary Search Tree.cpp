#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define NMAX 1001

int tree[NMAX];
int order[NMAX];
int N;
int pos = 1;

int myCompare(const void *p1, const void *p2)
{
	return *(int *)p1 - *(int *)p2;
}
void buildTree(int r)
{
	if (r > N)
		return;
	int lson = r << 1, rson = (r << 1) + 1;
	buildTree(lson);
	tree[r] = order[pos++];
	buildTree(rson);
}
int main()
{
	scanf("%d", &N);
	int i;
	for (i = 1; i <= N; ++i) 
		scanf("%d", order + i);
	qsort(order + 1, N, sizeof(int), myCompare);
	buildTree(1);
	for (printf("%d", tree[1]), i = 2; i <= N; ++i)
		printf(" %d", tree[i]);
	return 0;
}