class Solution {
	public:
		int findMaxLength(vector<int>& nums) {
			unordered_map<int,int>hash;
			hash[0]=-1;
			int cnt1=0,maxlen=0,gap01,i;
			for(i=0; i<nums.size(); ++i) {
				if(nums[i]==1)
					++cnt1;
				gap01=i+1-(cnt1<<1);
				if(hash.count(gap01))
					maxlen=max(maxlen,i-hash[gap01]);
				else
					hash[gap01]=i;
			}
			return maxlen;
		}
};
