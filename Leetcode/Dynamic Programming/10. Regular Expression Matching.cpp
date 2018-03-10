//题目是这种套路型经典字符串DP问题，但是题意有点问题，感觉，通过了348case,  aaa aaaa    ans:false   my:true;
class Solution {
	public:
		bool isMatch(string p, string s) {
			int slen=s.length();
			int plen=p.length();
			vector< vector<bool> >dp(plen+1,vector<bool>(slen+1,false));
			dp[0][0]=true;
			for (int i=1; i<=plen; ++i) {
				dp[i][0]=true;
				for (int j=1; j<=slen; ++j) {
					if (p[i-1]=='*')
						dp[i][j]=dp[i-1][j]|dp[i-1][j-1];
					else if (p[i-1]=='.'||p[i-1]==s[j-1]||s[j-1]=='.')
						dp[i][j]=dp[i-1][j-1];
					else if (s[j-1]=='*')
						dp[i][j]=dp[i][j-1]|dp[i-1][j-1];
				}
			}
			return dp[plen][slen];
		}
};

class Solution {
	public:
		bool isMatch(string s, string p) {
			int m = s.length(), n = p.length();
			vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
			dp[0][0] = true;
			for (int i = 0; i <= m; i++)
				for (int j = 1; j <= n; j++)
					if (p[j - 1] == '*')
						dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
					else
						dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			return dp[m][n];
		}
};
