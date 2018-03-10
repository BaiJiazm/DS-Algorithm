#include<iostream>
#include<cmath>
using namespace std;

void test(){
	long long h=-1;
	cout<<(unsigned long long)h<<endl;
	unsigned long long uh=1;
	cout<<(uh<<63)-1 <<endl;
	for(int i=1;i<=20;++i)
		cout<<'*' ;
}

int main(){
	long long h;		
	while(cin>>h){
		cout<<((int)sqrt(1+4*h)-1)/2<<endl;
	}
	return 0;
}
