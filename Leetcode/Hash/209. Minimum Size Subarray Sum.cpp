class Solution {
	public:
		int minSubArrayLen(int s, vector<int>& nums) {
			int begin=0,end=0,sum=0,minlen=INT_MAX;
			for(int end=0; end<nums.size();) {
				sum+=nums[end++];
				while(sum>=s) {
					minlen=min(minlen,end-begin);
					sum-=nums[begin++];
				}
			}
			return minlen==INT_MAX?0:minlen;
		}
};
