#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

#define startFare 3500

const int rt[] = {0, 3,10,20,25,30,35,45 };
const int bt[] = { 0,1500,4500,9000,35000,55000,80000,300000 };
int at[8] = { 0 };

int main()
{
	//freopen("test2.txt", "r", stdin);

	int i;
	for (i = 1; i <= 7; ++i)
		at[i] = at[i - 1] + (bt[i] - bt[i - 1])*(100 - rt[i]) / 100;

	int T;
	while (scanf("%d", &T) != EOF) {
		if (T <= 3500) {
			printf("%d\n", T);
			continue;
		}

		int t = T - startFare;
		for (i = 1; i <= 7 && t >= at[i]; ++i);

		int A = bt[i - 1] + (t - at[i - 1]) * 100 / (100 - rt[i]);
		printf("%d\n", A + startFare);
	}
	return 0;
}