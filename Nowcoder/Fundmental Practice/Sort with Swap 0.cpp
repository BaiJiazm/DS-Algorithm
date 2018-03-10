#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NMAX 100000

int master[NMAX];
int vice[NMAX];
int swapTime = 0;
int pos0, pos1;
int N;

void swap(int m1, int v1)
{
	master[m1] ^= master[v1];
	master[v1] ^= master[m1];
	master[m1] ^= master[v1];
	++swapTime;
}
void print()
{
	int i;
	printf("\nmaster:\n");
	for (i = 0; i < N; ++i)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i < N; ++i)
		printf("%d ", master[i]);
	printf("\nvice:\n");
	for (i = 0; i < N; ++i)
		printf("%d ", i);
	printf("\n");
	for (i = 0; i < N; ++i)
		printf("%d ",vice[i]);
}
void start()
{
	pos0 = vice[0];
	while (pos0) {
		swap(pos0, vice[pos0]);
		pos0 = vice[pos0];
	}
	for (int i = 0; i < N; ++i)
		if (master[i] != i) {
			swap(0, i);
			vice[0] = i;
			vice[master[0]] = 0;
			start();
		}
}
int main()
{
	scanf("%d", &N);
	int i;
	int n;
	for (i = 0; i < N; ++i) {
		scanf("%d", &n);
		master[i] = n;
		vice[n] = i;
	}
	start();
	printf("%d", swapTime);
	return 0;
}