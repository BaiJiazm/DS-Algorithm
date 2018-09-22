class Solution {
	public:
		int findUnsortedSubarray(vector<int>& nums) {
			if(nums.empty())
				return 0;
			vector<int>tnum(nums);
			sort(tnum.begin(),tnum.end());
			int begin=0,end=tnum.size()-1;
			for(; begin<nums.size()&&tnum[begin]==nums[begin];)
				++begin;
			if(begin>end)
				return 0;
			for(; end>=0&&tnum[end]==nums[end];)
				--end;
			return end-begin+1;
		}
};
