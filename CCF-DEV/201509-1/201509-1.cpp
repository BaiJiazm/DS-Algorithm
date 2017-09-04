#include<iostream>
using namespace std;

int main() {
	int n;
	while(scanf("%d",&n)!=EOF) {
		int i;
		int last,cur;
		int ans=0;
		for (i=0; i<n; ++i) {
			scanf("%d",&cur);
			if (!i)
				++ans;
			else if (cur!=last)
				++ans;
			last=cur;
		}
		printf("%d",ans);
	}
	return 0;
}
