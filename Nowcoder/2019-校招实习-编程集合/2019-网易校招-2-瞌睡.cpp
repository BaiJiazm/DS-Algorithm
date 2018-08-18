#include <bits/stdc++.h>
using namespace std;

int main() {
//	freopen("test1.txt", "r", stdin);

	int n, k;
	while(scanf("%d %d", &n, &k)!=EOF) {
		vector<int>value(n);
		vector<int>flag(n);
		int i, v;
		int sum=0, ans=0;
		for (i=0; i<n; ++i) {
			scanf("%d", &v);
			value[i]=v;
		}
		for (i=0; i<n; ++i) {
			scanf("%d", &v);
			flag[i]=v;
			if(v) {
				sum+=value[i];
			}
		}
		k=min(k, n);
		for(i=0; i<k; ++i) {
			if(flag[i]==0) {
				sum+=value[i];
			}
		}
		ans=sum;
		for(i=k; i<n; ++i) {
			sum=sum+(flag[i]==0?value[i]:0)-(flag[i-k]==0?value[i-k]:0);
			ans=max(ans, sum);
		}
		printf("%d\n", ans);
	}
	return 0;
}
