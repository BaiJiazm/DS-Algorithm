class Solution {
	public:
		int maximumProduct(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			int size=nums.size();
			int ans1=nums[0]*nums[1]*nums[size-1];
			int ans2=nums[size-1]*nums[size-2]*nums[size-3];
			return max(ans1,ans2);
		}
};
