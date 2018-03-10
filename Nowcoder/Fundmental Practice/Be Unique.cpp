#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define NMAX 100000

int main()
{
	//freopen("dataIn.txt", "r", stdin);
	//freopen("dataOut.txt", "w", stdout);

	int N;
	int n[NMAX + 1];
	int t;

	while (scanf("%d", &N) != EOF) {
		memset(n, 0, sizeof(n));
		vector<int>v;

		int i;
		for (i = 1; i <= N; ++i) {
			scanf("%d", &t);
			if (!n[t]++)
				v.push_back(t);
		}
		for (i = 0; i < v.size();++i)
			if (n[v[i]] == 1) {
				printf("%d", v[i]);
				break;
			}
		if (i == v.size())
			printf("None");
		printf("\n");
	}
	return 0;
}