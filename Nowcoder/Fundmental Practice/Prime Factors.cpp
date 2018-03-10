#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
using namespace std;

int main()
{
	long n;
	cin >> n;

	int temN = n;
	int sqr = (int)sqrt(n) + 1;
	vector<pair<int, int>>ans;

	int i;
	for (i = 2; i < sqr; ++i) {
		if (temN%i == 0){
			ans.push_back(pair<int, int>(i, 1));
			temN /= i;
			while (temN%i == 0) {
				++ans.back().second;
				temN /= i;
			}
			if (temN == 1)
				break;
		}
	}
	if (temN != 1)
		ans.push_back(pair<int, int>(temN, 1));

	if (temN == n)
		printf("%d=%d", n, n);
	else {
		printf("%d=", n);
		for (i = 0; i < ans.size(); ++i) {
			if (i != 0)
				printf("*");
			printf("%d", ans[i].first);
			if (ans[i].second != 1)
				printf("^%d", ans[i].second);
		}
	}
	return 0;
}
