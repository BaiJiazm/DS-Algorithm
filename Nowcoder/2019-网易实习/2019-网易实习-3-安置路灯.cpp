#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t, n;
	char ch;
	int i, ans;
	while(cin>>t) {
		while(t--) {
			vector<char>v;
			cin>>n;
			while(n--) {
				cin>>ch;
				v.push_back(ch);
			}
			ans=0;
			for (i=0; i<v.size(); ++i) {
				if(v[i]=='X')
					continue;
				++ans;
				v[i]='X';
				if(i+1<v.size()) {
					v[i+1]='X';
				}
				if(i+2<v.size()) {
					v[i+2]='X';
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
