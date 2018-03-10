#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct Node {
	int id, v1, v2, lv;
}node[100005];
bool cmp(const Node& a, const Node& b) {
	if (a.lv != b.lv) return a.lv < b.lv;
	if (a.v1 + a.v2 == b.v1 + b.v2) {
		if (a.v1 == b.v1) {
			return a.id < b.id;
		}
		return a.v1 > b.v1;
	}
	return a.v1 + a.v2 > b.v1 + b.v2;
}

int main()
{
	int n, low, high, id, v1, v2, cnt = 0;
	scanf("%d%d%d", &n, &low, &high);
	for (int i = 0; i < n; ++i, ++cnt) {
		scanf("%d%d%d", &node[cnt].id, &node[cnt].v1, &node[cnt].v2);
		if (node[cnt].v1 >= low && node[cnt].v2 >= low) {
			if (node[cnt].v1 >= high && node[cnt].v2 >= high) {
				node[cnt].lv = 1;
			}
			else if (node[cnt].v1 >= high) {
				node[cnt].lv = 2;
			}
			else if (node[cnt].v1 >= node[cnt].v2) {
				node[cnt].lv = 3;
			}
			else {
				node[cnt].lv = 4;
			}
		}
		else {
			--cnt;
		}
	}
	sort(node, node + cnt, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; ++i) {
		printf("%d %d %d\n", node[i].id, node[i].v1, node[i].v2);
	}

	return 0;
}