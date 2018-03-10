class Solution {
	public:
		int minDistance(string word1, string word2) {
			int len1=word1.length();
			int len2=word2.length();
			vector<vector<int>>dp(len1+1,vector<int>(len2+1,0));
			for(int i=1; i<=len1; ++i)
				for(int j=1; j<=len2; ++j) {
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
					if(word1[i-1]==word2[j-1])
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
				}
			return len1+len2-dp[len1][len2]*2;
		}
};
