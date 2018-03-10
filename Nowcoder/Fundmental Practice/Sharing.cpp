#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define MAXADDR 99999
#define charNum 128

struct Node {
	int addr;
	char key;
	int next;
};

struct Node L[MAXADDR + 1];

int main()
{
	//freopen("dataIn.txt", "r", stdin);
	//freopen("dataOut.txt", "w", stdout);

	int word1Addr, word2Addr;
	int N;

	while (scanf("%d %d %d", &word1Addr, &word2Addr, &N)!=EOF) {
		int i = N;
		struct Node tem;
		while (i--) {
			scanf("%d %c %d", &tem.addr, &tem.key, &tem.next);
			L[tem.addr] = tem;
		}

		vector<set<int>>vs(charNum, set<int>());
		int p = word1Addr, q = word2Addr;
		int ans = -1;

		while (p != -1) {
			vs[L[p].key].insert(p);
			p = L[p].next;
		}

		while (q != -1) {
			if (vs[L[q].key].find(q) != vs[L[q].key].end()) {
				ans = q;
				break;
			}
			q = L[q].next;
		}
		printf("%d\n", ans);
	}
	return 0;
}