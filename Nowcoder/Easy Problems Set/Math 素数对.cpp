#include <iostream>
#include <cmath>
using namespace std;

#define N 1010

int isPrimer(int num) {
	int n1, in, i;
	for (i=2, in=sqrt(num)+1; i<=in; ++i) {
		if(num/i*i==num) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int primer[N];
	for (int i=1; i<N; ++i) {
		primer[i]=isPrimer(i);
	}

	int n;
	while(cin>>n) {
		int ans=0;
		for (int i=1; i<=n/2; ++i) {
			ans+=primer[i]&&primer[n-i];
		}
		cout<<ans<<endl;
	}
}
