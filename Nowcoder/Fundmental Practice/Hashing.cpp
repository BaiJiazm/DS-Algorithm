#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MSize 10000
bool b[MSize] = { false };

int isPrime(int n)
{
	if (n == 1)
		return false;
	int q = (int)sqrt(n);
	int i;
	for (i = 2; i <= q; ++i)
		if (n%i == 0)
			return false;
	return true;
}
int main()
{
	int size, N;
	scanf("%d %d", &size, &N);
	while (!isPrime(size))
		++size;
	int i;
	int t, hash;
	while (N--) {
		scanf("%d", &t);
		for (i = 0; i < size; ++i) {
			hash = (t + i*i) % size;
			if (!b[hash]) {
				b[hash] = true;
				printf("%d%s", hash, N ? " " : "\n");
				break;
			}
		}
		if (i == size)
			printf("-%c", N ? ' ' : '\n');
	}
	return 0;
}