#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int T,t;
	int h,m,s;
	int ss;
	
	const int cst=12*3600;
	cin>>T;
	while(T--){
		cin>>h>>m>>s;
		cin>>t;
		t%=cst;
		ss=h*3600+m*60+s;
		ss=(ss+t)%cst;
		
		double a1=(ss*1.0/cst)*360;
		double a2=(ss%3600/3600.0)*360;
		double a3=abs(a1-a2);
		double ans=a3>180?360-a3:a3; 
		printf("%.4lf\n",ans);
	}
	
	return 0;
}
