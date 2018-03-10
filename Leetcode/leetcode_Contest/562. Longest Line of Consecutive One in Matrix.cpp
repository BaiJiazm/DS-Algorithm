class Solution {
	public:
		int longestLine(vector<vector<int>>& M) {
			int row=M.size();
			if(!row)
				return 0;
			int col=M[0].size();
			if(!col)
				return 0;
			if(row==1&&col==1&&M[0][0])
				return 1;
			int ans=0;
			vector<vector<int>>dp(M);
			int i,j;
			for(i=0; i<row; ++i)
				for(j=1; j<col; ++j)
					if(dp[i][j]) {
						dp[i][j]=dp[i][j-1]+1;
						ans=max(ans,dp[i][j]);
					}
			dp=M;
			for(j=0; j<col; ++j)
				for(i=1; i<row; ++i)
					if(dp[i][j]) {
						dp[i][j]=dp[i-1][j]+1;
						ans=max(ans,dp[i][j]);
					}
			dp=M;
			for(i=1; i<row; ++i)
				for(j=1; j<col; ++j)
					if(dp[i][j]) {
						dp[i][j]=dp[i-1][j-1]+1;
						ans=max(ans,dp[i][j]);
					}
			dp=M;
			for(i=1; i<row; ++i)
				for(j=col-2; j>=0; --j)
					if(dp[i][j]) {
						dp[i][j]=dp[i-1][j+1]+1;
						ans=max(ans,dp[i][j]);
					}
			return ans;
		}
};
