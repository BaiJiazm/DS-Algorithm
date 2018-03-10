#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	long long x, p,n;
	while(~scanf("%I64d %I64d %I64d",&x,&p,&n)&&x&&p&&n) {
		long long ans=0,i;
		for (i=p; i>p-n; --i)
			if ((x>>i)&1)
				ans=(ans<<1)|1;
			else
				ans<<=1;
		printf("%I64d\n",ans);
	}
	return 0;
}

//int main() {
//	long long x, p,n;
//	while(cin>>x>>p>>n) {
//		if (x||p||n) {
//			long long ans=0,i;
//			for (i=p; i>p-n; --i)
//				if ((x>>i)&1)
//					ans=(ans<<1)|1;
//				else
//					ans<<=1;
//			cout<<ans<<endl; 
//		}
//	}
//	return 0;
//}
