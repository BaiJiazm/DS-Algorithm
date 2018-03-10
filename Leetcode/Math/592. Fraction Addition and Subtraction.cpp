#include<iostream>
#include<sstream>
#include<string>
using namespace std;

class Solution {
	public:
		string fractionAddition(string expression) {
			if(expression.empty())
				return "0/1";
			stringstream ss(expression);
			int numer=0,dinom=1;
			int newn,newd;
			char ch;

			while(ss>>newn>>ch>>newd)	{
				int td=dinom*newd;
				int tn=numer*newd+newn*dinom;
				numer=tn;
				dinom=td;
				if(numer==0)
					dinom=1;
				else {
					int mcf=maxComonFactor(abs(dinom),abs(numer));
					numer/=mcf;
					dinom/=mcf;
				}
			}
			return to_string(numer)+"/"+to_string(dinom);
		}
		int maxComonFactor(int m,int n) {
			if(m<n)
				return maxComonFactor(n,m);
			return m%n==0?n:maxComonFactor(m%n,n);
		}
};

void test() {
	stringstream ss;
	string str;
	getline(cin,str);
	ss<<str;
	int i,j,k;
	char ch;
	while(ss>>i>>ch>>j) {
		cout<<i<<" "<<ch<<" "<<j<<endl;
	}
}

void test2() {
	cout<<" 5%-2= "<<5%-2<<endl;
	cout<<"-5% 2= "<<-5%2<<endl;
	cout<<" 7%-3= "<<7%-3<<endl;
	cout<<"-7% 3= "<<-7%3<<endl;

	cout<<"-2% 5= "<<-2% 5<<endl;
	cout<<" 2%-5= "<<2%-5<<endl;
	cout<<"-3% 7= "<<-3% 7<<endl;
	cout<<" 3%-7= "<<3%-7<<endl;
}

int main() {
	//test();
	test2();
	Solution s;
	string str="1/3-1/2";
	//cout<<s. fractionAddition(str);
	return 0;
}
