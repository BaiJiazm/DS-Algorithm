#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int l, int r) {
	return l>r?l:r;
}

int main() {
	char str[100];
	scanf("%s", str);
	int len = strlen(str);
	if(len==0) {
		cout<<0<<endl;
		return 0;
	}
	char *pend = str + len-1;
	int ans = 1;
	int i;
	for (i = 0; i < len; ++i) {
		char *left, *right;
		for (left = str + i, right = str + i; left >= str&&right <= pend&&*left == *right; ) {
			--left;
			++right;
		}
		ans = max(ans, right - left - 1);
		for (left = str + i, right = str + i + 1; left >= str&&right <= pend&&*left == *right; ) {
			--left;
			++right;
		}
		ans = max(ans, right - left - 1);
	}
	cout << ans << endl;
	return 0;
}
