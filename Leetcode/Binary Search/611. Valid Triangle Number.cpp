class Solution {
	public:
		int triangleNumber(vector<int>& nums) {
			sort(nums.begin(),nums.end());
			int ans=0;
			for(int i=0; i<(int)nums.size()-2; ++i)
				for(int j=i+1; j<(int)nums.size()-1; ++j) {
					int c=nums[i]+nums[j]-1;
					int cnt=upper_bound(nums.begin()+j+1,nums.end(),c)-nums.begin()-j-1;
					ans+=cnt;
				}
			return ans;
		}
};
