#include <iostream>
#include <cstring>
using namespace std;
#define N 1001

int main() {
//	freopen("201703-2-test.txt", "r", stdin);
	
	int n,m;
	int p,q;
	int i;

	int que[N];
	while(scanf("%d %d", &n, &m)!=EOF) {
		for (i=1; i<=n; ++i) {
			que[i]=i;
		}
		while(m--) {
			scanf("%d %d", &p, &q);
			for (i=1; i<=n; ++i)	{
				if(que[i]==p)
					break;
			}
			if(q<0) {
				memcpy(que+i+q+1, que+i+q, sizeof(int)*(-q));
				que[i+q]=p;
			} else {
				memcpy(que+i, que+i+1, sizeof(int)*(q));
				que[i+q]=p;
			}
		}
		for(i=1; i<=n; ++i) {
			printf("%d", que[i]);
			if(i!=n)
				printf(" ");
		}
	}
	return 0;
}
