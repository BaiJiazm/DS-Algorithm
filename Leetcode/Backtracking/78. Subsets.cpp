class Solution {
	public:
		vector<vector<int>> subsets(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>tem;
			solve(ans,nums,0,tem);
			return ans;
		}
		void solve(vector<vector<int>>&ans,vector<int>&nums,int index,vector<int>&tem) {
			if (index==nums.size()) {
				ans.push_back(tem);
				return ;
			}
			tem.push_back(nums[index]);
			solve(ans,nums,index+1,tem);
			tem.pop_back();
			solve(ans,nums,index+1,tem);
		}
};
