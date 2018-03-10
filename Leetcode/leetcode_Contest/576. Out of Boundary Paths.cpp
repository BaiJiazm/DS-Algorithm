class Solution {
	public:
		int findPaths(int m, int n, int N, int i, int j) {
			long long dp[55][55][55];
			memset(dp,0,sizeof(dp));
			int t1;
			for(t1=1; t1<=n; ++t1) {
				++dp[1][t1][1];
				++dp[m][t1][1];
			}
			for(t1=1; t1<=m; ++t1) {
				++dp[t1][1][1];
				++dp[t1][n][1];
			}
			int ii,jj;
			for(t3=2; t3<=N; ++t3) {
				for(ii=1; ii<=m; ++ii)
					for(jj=1; jj<=n; ++jj) {
						dp[ii][jj][t3]+=dp[ii][jj-1][t3-1];
						dp[ii][jj][t3]+=dp[ii][jj+1][t3-1];
						dp[ii][jj][t3]+=dp[ii-1][jj][t3-1];
						dp[ii][jj][t3]+=dp[ii+1][jj][t3-1];
						dp[ii][jj][t3]%=(1000000007);
					}
			}
			long long ans=0;
			for(ii=1; ii<=N; ++ii)
				ans+=dp[i+1][j+1][ii];
			return ans%(1000000007);
		}
};
