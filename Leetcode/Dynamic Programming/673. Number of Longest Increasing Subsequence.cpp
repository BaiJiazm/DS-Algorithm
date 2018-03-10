/*
算是非常简单的DP问题吧，竟然提交了四次。
1.maxlist未更新
2.node的first，second 含义不清晰，写错。 
*/
class Solution {
	public:
		typedef pair<int,int> node;
		int findNumberOfLIS(vector<int>& nums) {
			int size=nums.size();
			vector<node>dp(size, node(1, 1));
			int i, j;
			int maxlis=0;
			int ans=0;
			for(i=0; i<size; ++i) {
				for(j=i-1; j>=0; --j) {
					if(nums[j]<nums[i]) {
						if(dp[j].first+1>dp[i].first)
							dp[i]=node(dp[j].first+1, dp[j].second);
						else if(dp[j].first+1==dp[i].first)
							dp[i].second+=dp[j].second;
					}
				}
				if(maxlis==dp[i].first)
					ans+=dp[i].second;
				else if(maxlis<dp[i].first) {
					ans=dp[i].second;
					maxlis=dp[i].first;
				}
			}
			return ans;
		}
};
