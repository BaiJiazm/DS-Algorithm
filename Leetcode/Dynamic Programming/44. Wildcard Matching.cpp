class Solution {
	public:
		bool isMatch(string s, string p) {
			int slen=s.length();
			int plen=p.length();
			vector<vector<bool>>dp(slen+1,vector<bool>(plen+1,false));
			dp[0][0]=true;
			for (int i=1; i<=plen; ++i)
				if (dp[0][i-1]&&p[i-1]=='*')
					dp[0][i]=true;
			for (int i=1; i<=slen; ++i)
				if (dp[i-1][0]&&s[i-1]=='*')
					dp[i][0]=true;
			for (int i=1; i<=slen; ++i) {
				for (int j=1; j<=plen; ++j) {
					if(s[i-1]=='*'||p[j-1]=='*')
						dp[i][j]=dp[i-1][j-1]||dp[i][j-1]||dp[i-1][j];
					else if (s[i-1]=='?'||p[j-1]=='?'||s[i-1]==p[j-1])
						dp[i][j]=dp[i-1][j-1];
				}
			}
			return dp[slen][plen];
		}
};
