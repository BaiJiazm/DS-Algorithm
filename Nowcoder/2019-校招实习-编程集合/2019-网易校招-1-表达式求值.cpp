#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("test1.txt", "r", stdin);

	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c)!=EOF) {
		int ans1, ans2, t;
		t=max(a+b, a*b);
		ans1=max(t+c, t*c);
		t=max(b+c, b*c);
		ans2=max(t+a, t*a);
		printf("%d\n", max(ans1, ans2));
	}
	return 0;
}
