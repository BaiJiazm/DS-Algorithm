/*
	出错两次：
	1.t误写为i，自己未测试出来
	2.没有考虑数据范围。 
*/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
#define NMAX 55

int main(){
//	freopen("test.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int a[NMAX];
	long long dp[NMAX][NMAX][2];
	int n,k,d;
	int i,j,t;
	while(cin>>n){
		for(i=1;i<=n;++i)
			cin>>a[i];
		cin>>k>>d;
		
		for(i=1;i<=n;++i)
			dp[i][1][0]=dp[i][1][1]=a[i];
		for(j=2;j<=k;++j){
			for(i=j;i<=n;++i){
				for(t=max(i-d, 1);t<i;++t){
					long long v1=dp[t][j-1][0]*a[i];
					long long v2=dp[t][j-1][1]*a[i];
					dp[i][j][0]=min(dp[i][j][0], min(v1,v2));
					dp[i][j][1]=max(dp[i][j][1], max(v1,v2));
				}
			}
		}
		long long ans=pow(-50,9);
		for(i=k;i<=n;++i)
			ans=max(ans, dp[i][k][1]);
		cout<<ans<<endl;
	}
	return 0;
}
