#include <iostream>
#include <string>
using namespace std;

long long getSeg(int n1) {
	long long ret=0;
	for (int i=0; i<n1; ++i) {
		ret=ret*10+1;
	}
	return ret;
}

void solve(int n, int m) {
	int len=to_string(n).length();
	string ans;
	for (int i=0; m>0&&i<len; ++i) {
		long long seg=getSeg(len-i);
		int t=m/seg;
		if(i==0){
			ret.push_back(t+1); 
		}
	}

}

int main() {
	long long n,m;
	while(cin>>n>>m) {

	}
	return 0;
}
