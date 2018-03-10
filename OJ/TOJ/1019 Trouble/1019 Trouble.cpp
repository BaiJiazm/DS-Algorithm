#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=5100;
int num[maxn];

int main() {
	int n;
	while(cin>>n)
		if (n) {
			int i;
			for(i=0; i<n; ++i)
				cin>>num[i];
			if (n&1) {
				printf("No\n");
				continue;
			}
			sort(num,num+n);
			int h=num[0]+num[n-1];
			for(i=1; i<n>>1; ++i)
				if(num[i]+num[n-i-1]!=h)
					break;
			if(i==n>>1)
				printf("Yes\n");
			else
				printf("No\n" );
		}
	return 0;
}
