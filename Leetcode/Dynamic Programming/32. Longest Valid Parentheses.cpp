#include "headFile"

class Solution {
	public:
		int longestValidParentheses(string s) {
			int slen=s.length();
			vector<int>dp(slen+1);
			dp[0]=0;
			int ans=0;
			for (int i=1; i<=slen; ++i) {
				if (s[i-1]=='(')
					dp[i]=0;
				else {
					int pos=i-2-dp[i-1];
					if (pos>=0&&s[pos]=='(')
						dp[i]=dp[i-1]+2+dp[pos];
					else
						dp[i]=0;
				}
				ans=max(ans,dp[i]);
			}
			return ans;
		}
};

int main()
{
	string str("()()(()()(");
	Solution s;
	cout<<s.longestValidParentheses(str);
	return 0;
}
