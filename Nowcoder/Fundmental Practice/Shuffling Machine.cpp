#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<cstring>
using namespace std;

#define N 54
const char pokerChar[] = { 'S','H','C','D','J' };
int o[N + 1];
int t[N + 1];
int r[N + 1];

void printPoker()
{
	int i;
	int c, d;

	for (i = 1; i <= N; ++i) {
		c = t[i] / 13;
		d = t[i] % 13;
		if (!d)
			d = 13, --c;
		if (i != 1)
			printf(" ");
		printf("%c%d", pokerChar[c], d);
	}
}
int main()
{
	int K;
	while (scanf("%d", &K) != EOF) {
		int i;
		for (i = 1; i <= N; ++i) {
			scanf("%d", o + i);
			t[i] = i;
		}

		while (K--) {
			for (i = 1; i <= N; ++i)
				r[o[i]] = t[i];
			memcpy(t, r, sizeof(t));
		}
		printPoker();
	}
	return 0;
}

