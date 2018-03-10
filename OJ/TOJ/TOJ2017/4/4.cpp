#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
using namespace std;

char ch[400][400];

int main() {
	int m,n;
	int i,j;
	cin>>m>>n;
	for(i=1; i<=m; ++i) {
		for(j=1; j<=n; ++j)
			cin>>ch[i][j];
	}
	if(m==1&&n==1)
		cout<<"-1"<<endl;
	else {
		int ans=0;
		for(i=2; i<n; ++i) {
			if(ch[1][i]=='^')
				ans++;
			if(ch[m][i]=='v')
				ans++;
		}
		for(i=2; i<m; ++i) {
			if(ch[i][1]=='<')
				ans++;
			if(ch[i][n]=='>')
				ans++;
		}
		if(m==1) {
			if(ch[1][1]=='^'||ch[1][1]=='<'||ch[1][1]=='v')
				ans++;
			if(ch[1][n]=='^'||ch[1][n]=='>'||ch[1][1]=='v')
				ans++;
		} else if(n==1) {
			if(ch[1][1]=='^'||ch[1][1]=='<'||ch[1][1]=='>')
				ans++;
			if(ch[m][1]=='<'||ch[m][1]=='>'||ch[m][1]=='v')
				ans++;
		} else {
			if(ch[1][1]=='^'||ch[1][1]=='<')
				ans++;
			if(ch[1][n]=='^'||ch[1][n]=='>')
				ans++;
			if(ch[m][1]=='<'||ch[m][1]=='v')
				ans++;
			if(ch[m][n]=='>'||ch[m][n]=='v')
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
