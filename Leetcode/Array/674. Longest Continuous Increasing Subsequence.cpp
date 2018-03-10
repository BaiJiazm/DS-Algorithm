//very easy problem 
class Solution {
	public:
		int findLengthOfLCIS(vector<int>& nums) {
			int ans=0;
			int tem=0,i;
			for(i=0; i<nums.size(); ++i) {
				if(i==0||nums[i]>nums[i-1])
					ans=max(ans, ++tem);
				else
					tem=1;
			}
			return ans;
		}
};
