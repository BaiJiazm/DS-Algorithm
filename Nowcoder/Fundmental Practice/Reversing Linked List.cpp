#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

#define MAXADDR 100000

struct Node {
	int data;
	int next;
};

struct Node n[MAXADDR + 1];
vector<vector<int>>vv;

int main()
{
	int N, K;
	int head;
	while (scanf("%d %d %d", &head, &N, &K) != EOF) {
		vv.clear();
		vv.resize((N + K - 1) / K);

		int i, j;
		int addr, data, next;
		for (i = N; i--;) {
			scanf("%d %d %d", &addr, &data, &next);
			n[addr] = { data,next };
		}

		for (addr = head, i = 0; addr != -1; addr = n[addr].next)
			if ((int)vv[i].size() < K)
				vv[i].push_back(addr);
			else
				vv[++i].push_back(addr);

		vector<int>ans;
		for (i = 0; i<(int)vv.size()&&vv[i].size() == K; ++i)
			for (j = K - 1; j >= 0; --j)
				ans.push_back(vv[i][j]);

		for (j = 0;  i<(int)vv.size() && j < (int)vv[i].size(); ++j)
			ans.push_back(vv[i][j]);
		
		ans.push_back(-1);
		for (i = 0, addr = ans[0]; (next = ans[++i]) != -1; addr = next)
			printf("%05d %d %05d\n", addr, n[addr].data, next);
		printf("%05d %d %d\n", addr, n[addr].data, -1);

		return 0;
	}
	return 0;
}