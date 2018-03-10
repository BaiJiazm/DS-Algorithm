#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int N, K, C;
	char name[5];
	int intName;
	int cno;

	while (scanf("%d %d", &N, &K)!= EOF) {
		vector<vector<int>>vv;
		vv.assign(K+1, vector<int>());
		
		while (N--) {
			scanf("%s %d", name, &C);
			intName = name[0] << 24 | name[1] << 16 | name[2] << 8 | name[3];
			while (C--) {
				scanf("%d", &cno);
				vv[cno].push_back(intName);
			}
		}
		
		vector<int>::iterator it;

		for (int i = 1; i <= K; ++i) {
			sort(vv[i].begin(), vv[i].end());
			printf("%d %d\n", i, vv[i].size());
			for (it = vv[i].begin(); it < vv[i].end(); ++it) {
				intName = *it;
				printf("%c%c%c%c\n", char(intName >> 24), char(intName >> 16), char(intName >> 8), char(intName));
			}
		}
	}
	return 0;
}