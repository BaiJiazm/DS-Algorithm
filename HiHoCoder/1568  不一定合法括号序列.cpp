#include<iostream>
#include<cstring>
using namespace std;
#define NMAX 305
#define M 1000000007

int dp[NMAX<<1][NMAX][NMAX];

int main() {
	int n,k;
	while(cin>>n>>k) {
		memset(dp, 0, sizeof(dp));
		dp[0][0][0]=1;
		for(int i=0; i<=2*n; ++i) {
			for(int left=0; left<=min(i,n); ++left) {
				for(int right=0; right<=min(i,n); ++right) {
					long long ll=dp[i+1][left+1][right];
					ll+=dp[i][left][right];
					dp[i+1][left+1][right]=ll%M;

					if(left>0){
						ll=dp[i+1][left-1][right];
						ll+=dp[i][left][right];
						dp[i+1][left-1][right]=ll%M;
					}
					else{
						ll=dp[i+1][left][right+1];
						ll+=dp[i][left][right];
						dp[i+1][left][right+1]=ll%M;
					}
				}
			}
		}

		cout<<dp[n<<1][k][k]<<endl;
	}
	return 0;
}


