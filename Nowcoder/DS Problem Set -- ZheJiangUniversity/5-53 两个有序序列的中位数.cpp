#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N);

	int *n1 = (int *)malloc(N*sizeof(int));
	int *n2 = (int *)malloc(N*sizeof(int));
	int *n = (int *)malloc(2 * N*sizeof(int));

	int i, j, k;
	
	for (i = 0; i < N; ++i)
		scanf("%d", n1 + i);
	
	for (i = 0; i < N; ++i)
		scanf("%d", n2 + i);

	for (i = 0, j = 0, k = 0; i < N&&j < N;)
		if (n1[i] < n2[j])
			n[k++] = n1[i++];
		else
			n[k++] = n2[j++];

	while (i < N)
		n[k++] = n1[i++];

	while (j < N)
		n[k++] = n2[j++];

	printf("%d", n[(2 * N - 1) / 2]);

	free(n1);
	free(n2);
	free(n);

	return 0;
}
