#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
#include<cstring>
#include<algorithm>
using namespace std;

//解法一	栈模拟
struct node {
	int height;
	int weight;
};
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		stack<node>s;
		int i, tem;
		int h, maxS = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &h);
			tem = 0;
			while (!s.empty() && s.top().height > h) {
				maxS = max(maxS, s.top().height*(s.top().weight + tem));
				tem += s.top().weight;
				s.pop();
			}
			s.push({ h,1 + tem });
		}
		tem = 0;
		while (!s.empty()) {
			maxS = max(maxS, s.top().height*(s.top().weight + tem));
			tem += s.top().weight;
			s.pop();
		}
		printf("%d\n", maxS);
	}
	return 0;
}

//解法二	DP
#define NMAX 1000
int nums[NMAX];
int dp[NMAX][NMAX];

int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		memset(dp, 0x3f, sizeof(dp));
		int ans;
		int i, j;
		for (i = 0; i < n; ++i)
			scanf("%d", nums + i);
		ans = dp[0][0] = nums[0];
		for (i = 1; i < n; ++i) {
			for (j = i; j >= 0; --j) {
				dp[j][i] = min(dp[j][i - 1], nums[i]);
				ans = max(ans, (i - j + 1)*dp[j][i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}