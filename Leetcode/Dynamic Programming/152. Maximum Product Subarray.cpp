class Solution {
	public:
		int maxProduct(vector<int>& nums) {
			if(nums.empty())
				return 0;
			int maxMul=nums[0];
			int minMul=nums[0];
			int ans=nums[0];
			for(int i=1; i<nums.size(); i++) {
				int a = maxMul*nums[i];
				int b = minMul*nums[i];
				maxMul=max(max(a,b),nums[i]);
				minMul=min(min(a,b),nums[i]);
				ans=max(ans,maxMul);
			}
			return ans;
		}
};

