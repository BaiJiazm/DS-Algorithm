#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <algorithm>  

using namespace std;

const int maxx = 26 * 26 * 26 * 10 + 1;

int hashName(const char *name) {
	return (name[0] - 'A') * 26 * 26 * 10\
		+ (name[1] - 'A') * 26 * 10\
		+ (name[2] - 'A') * 10\
		+ (name[3] - '0');
}

vector<int> course[maxx];

int main() {
	int n, k, cid, sn, hname;
	char name[5];
	vector<int>::iterator ib, ie;

	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; ++i) {
		scanf("%d %d", &cid, &sn);
		for (int j = 0; j < sn; ++j) {
			scanf("%s", name);
			hname = hashName(name);
			course[hname].push_back(cid);
		}
	}

	for (int i = 0; i < n; ++i) {
		scanf("%s", name);
		hname = hashName(name);

		printf("%s", name);
		printf(" %d", course[hname].size());

		sort(course[hname].begin(), course[hname].end());

		ib = course[hname].begin();
		ie = course[hname].end();

		for (; ib != ie; ++ib) {
			printf(" %d", *ib);
		}
		printf("\n");
	}
	return 0;
}