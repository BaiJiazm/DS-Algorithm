class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int maxSum=INT_MIN,tmpSum=0;
			for(int i=0; i<nums.size(); i++) {
				tmpSum=max(tmpSum+nums[i],nums[i]);//连续累加时的两种情况
				maxSum=max(maxSum,tmpSum);//更新最大值
			}
			return maxSum;
		}
};
