#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int N, M;
int * H;

void heapAdjust(int n)
{
	int i = H[n];
	int j;

	while ((j = n / 2) && H[j] > i) {
		H[n] = H[j];
		n = j;
	}
	H[n] = i;
}

void printHeapPath(int pos)
{
	while (pos != 1) {
		printf("%d ", H[pos]);
		pos /= 2;
	}
	printf("%d\n", H[pos]);

}
int main()
{
	scanf("%d %d", &N, &M);
	H = new int[N + 1];

	int i;
	for (i = 1; i <= N; ++i) {
		scanf("%d", H + i);
		heapAdjust(i);
	}

	while (M--) {
		scanf("%d", &i);
		printHeapPath(i);
	}

	return 0;
}