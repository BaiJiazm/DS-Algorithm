class Solution {
	public:
		bool canJump(vector<int>& nums) {
			int maxIndex=0;
			for (int i=0; maxIndex+1<nums.size()&&i<=maxIndex; ++i)
				maxIndex=max(maxIndex,i+nums[i]);
			return maxIndex+1>=nums.size();
		}
};
