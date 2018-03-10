#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int N;
	while(~scanf("%d",&N)&&N) {
		int nmax=sqrt(2*N);
		int mid,n;
		int ans=0;
		for (n=1; n<=nmax; ++n) {
			mid=N/n;
			if((n&1)&&mid*n==N)
				++ans;
			else if (!(n&1)&&(mid*2+1)*n/2==N)
				++ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
