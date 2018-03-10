class Solution {
	public:
#define MOD 1000000007
		int findDerangement(int n) {
			if(n<=3)
				return n-1;
			vector<long long>dp(n+1);
			dp[0]=dp[1]=0;
			dp[2]=1;
			for(int i=3; i<=n; ++i)
				dp[i]=((i-1)*(dp[i-2]+dp[i-1]))%MOD;
			return dp[n];
		}
};
