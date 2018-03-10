#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;

int main() {
	char ch[1000];
	long long k,m,n;
	long long ans,a,b;
	int i=0;
	int flag;
	while(~scanf("%I64d %I64d %I64d",&n,&m,&k)) {
		flag=0;
		++i;
		if(n+m<k) {
			flag=0;
		} else if((n&1)&&(m&1)&&!(k&1)) {
			flag=0;
		} else if(!(n&1)&&!(m&1)&&(k&1)) {
			flag=0;
		} else {
			if(n&1) {
				a=n;//ÆæÊý
				b=m;
			} else {
				a=m;
				b=n;
			}
			if(k&1) {
				if(a<k) {
					flag=0;
				} else {
					ans=a/k+1;
					flag=1;
				}
			} else {
				if(b<k) {
					flag=0;
				} else {
					ans=b/k+1;
					flag=1;
				}
			}
		}
		if(flag) {
			//printf("#%d\n",i);
			cout<<ans<<endl;
		} else {
			//printf("#%d\n",i);
			printf("-1\n");
		}

	}
	return 0;
}
