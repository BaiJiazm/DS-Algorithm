#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NameLen 5

int compare(const void *p1,const void* p2)
{
	return strcmp((char *)p1, (char *)p2);
}

int compare1(const void *p1, const void* p2)
{
	return strcmp(*((char **)p1), *((char **)p2));
}

int BinarySearch(char **src,int left, int right, char *dst)
{
	int mid;
	while (left<=right)
	{
		mid = (left + right) / 2;
		int s = compare(src[mid], dst);
		if (s == 0)
			return 1;
		else if (s < 0)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	char ***course = (char ***)malloc((K + 1)*sizeof(char **));
	int* coursen = (int *)malloc((K + 1)*sizeof(int));
	int* n = (int *)malloc((K + 1)*sizeof(int));

	int i, j, r, k;
	for (i = 1; i <=K; ++i)
	{
		scanf("%d%d", &k, coursen + i);
		r = coursen[i];
		course[i] = (char **)malloc(r*sizeof(char *));
		for (j = 0; j < r; ++j)
		{
			course[i][j] = (char *)malloc(NameLen*sizeof(char));
			scanf("%s", course[i][j]);
		}
	}

	for (i = 1; i <= K; ++i)
		qsort(course[i], coursen[i], sizeof(char *), compare1);

	/*for (i = 1; i <= K; ++i)
	{
		printf("%d ", i);
		for (j = 0; j < coursen[i]; ++j)
			printf(" %s", course[i][j]);
		printf("\n");
	}*/

	char tem[NameLen];

	for (i = 0; i < N; ++i)
	{
		scanf("%s", tem);
		n[0] = 0;
		for (j = 1; j <= K;++j)
			if (BinarySearch(course[j], 0, coursen[j] - 1, tem))
			{
				n[0]++;
				n[n[0]] = j;
			}
		printf("%s %d", tem, n[0]);
		for (k = 1; k <= n[0]; ++k)
			printf(" %d", n[k]);

		printf("\n");
	}

	return 0;
}