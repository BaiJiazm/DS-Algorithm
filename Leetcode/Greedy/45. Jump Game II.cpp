class Solution {
	public:
		int jump(vector<int>& nums) {
			if (nums.empty())
				return 0;
			int step=0,cur=0,next=0;
			for (int i=0; cur<nums.size()-1; ++i) {
				next=max(next,nums[i]+i);
				if (i==cur) {
					cur=next;
					++step;
				}
			}
			return step;
		}
};
