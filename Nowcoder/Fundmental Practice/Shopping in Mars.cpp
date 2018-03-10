#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;

#define NMAX 100001

struct cutNode {
	int start;
	int end;
	int value;
};

int main()
{
	//freopen("dataIn.txt", "r", stdin);
	//freopen("dataOut.txt", "w", stdout);

	int N, M;
	int n[NMAX];
	vector<cutNode>equal;
	vector<cutNode>close;

	while (scanf("%d %d", &N, &M) != EOF) {
		int i, j, tem;
		int value;
		for (i = 1; i <= N; ++i)
			scanf("%d", n + i);

		for (i = 1, j = 1, value = 0; j <= N;) {
			tem = value + n[j];
			if (tem == M) {
				equal.push_back({ i,j,M });
				value = tem - n[i];
				++i;
				++j;
			}
			else if (tem < M) {
				value = tem;
				++j;
			}
			else {
				if (!equal.empty()) {
					if (close.empty())
						close.push_back({ i,j,tem });
					else {
						if (close[0].value>tem) {
							close.clear();
							close.push_back({ i,j,tem });
						}
						else if (close[0].value == tem)
							close.push_back({ i,j,tem });
					}
				}
				value -= n[i];
				++i;
			}
		}

		vector<cutNode>::iterator iter;
		if (!equal.empty())
			for (iter = equal.begin(); iter < equal.end(); ++iter)
				printf("%d-%d\n", iter->start, iter->end);
		else 
			for (iter = close.begin(); iter < close.end(); ++iter)
				printf("%d-%d\n", iter->start, iter->end);

		equal.clear();
		close.clear();
		//printf("\n");
	}
	return 0;
}