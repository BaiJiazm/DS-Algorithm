class Solution {
	public:
		string optimalDivision(vector<int>& nums) {
			string ans="";
			int size=nums.size();
			if(size==0)
				return ans;
			else if(size==1)
				return to_string(nums[0]);
			ans=to_string(nums[0])+"/";
			if(size>2)
				ans+="(";
			for(int i=1; i<size; ++i)
				ans+=to_string(nums[i])+"/";
			if(size>2)
				ans.back()=')';
			else
				ans.erase(ans.length()-1);
			return ans;
		}
};
