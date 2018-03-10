//#include<cstdio>
//#include<cmath>
//#include<iostream>
//#include<iomanip>
//using namespace std;
//
//int main() {
//	int c,x,y;
//	double z;
//	cin>>c;
//	while(c--) {
//		scanf("%d %d %lf",&x,&y,&z);
//		int T=abs((x-y))*60;
//		if (!T)
//			printf("1.0000000\n");
//		else {
//			int T2=T*T;
//			double d2=(T-z)*(T-z);
//			double p=(T2-d2)/T2;
//			p=p*10000000+0.5;
//			p=(int)p/10000000.0;
//			printf("%.7lf\n",p);
//		}
//	}
//	return 0;
//}

#include<cstdio>
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int c,x,y;
	double z;
	cin>>c;
	while(c--) {
		cin>>x>>y>>z;
		int T=abs((x-y))*60;
		int T2=T*T;
		if (!T||z>=T)
			cout<<"1.0000000"<<endl;
		else {
			double d2=(T-z)*(T-z);
			double p=(T2-d2)/T2;
			int t=(int)(p*100000000+5);
			//cout<<t<<endl;
			t/=10;
			cout<<"0.";
			cout<<t/1000000%10;
			cout<<t/100000%10;
			cout<<t/10000%10;
			cout<<t/1000%10;
			cout<<t/100%10;
			cout<<t/10%10;
			cout<<t%10;
			cout<<endl;
//			p=p*10000000+0.5;
//			p=(int)p/10000000.0;
			//cout<<setiosflags(ios::fixed)<<setprecision(7)<<p<<endl;
		}
	}
	return 0;
}
