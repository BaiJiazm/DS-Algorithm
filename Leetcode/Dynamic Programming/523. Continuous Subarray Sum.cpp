#include "headFile"

class Solution {
	public:
		bool checkSubarraySum(vector<int>& nums, int k) {
			int size=nums.size();
			if (size<2)
				return false;
			if (k==0) {
				for (int i=1; i<size; ++i)
					if(!nums[i]&&!nums[i-1])
						return true;
				return false;
			}
			k=k>0?k:-k;
			vector<int>dp(size);
			for (int i=0; i<size; ++i) {
				dp[i]=nums[i];
				for(int j=i-1; j>=0; --j) {
					dp[j]+=nums[i];
					if (dp[j]%k==0)
						return true;
				}
			}
			return false;
		}
};
