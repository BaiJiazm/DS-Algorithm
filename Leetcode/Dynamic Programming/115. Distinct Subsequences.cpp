class Solution {
	public:
		int numDistinct(string s, string t) {
			int slen=s.length();
			int tlen=t.length();
			if (tlen>slen)
				return 0;
			vector<vector<int>>dp(slen+1,vector<int>(tlen+1,0));
			for (int i=0;i<=slen;++i)
				dp[i][0]=1;
			for(int i=1; i<=slen; ++i) {
				for(int j=1; j<=tlen; ++j) {
					if (s[i-1]==t[j-1])
						dp[i][j]+=dp[i-1][j-1]+dp[i-1][j];
					else
						dp[i][j]=dp[i-1][j];
				}
			}
			return dp[slen][tlen];
		}
};
