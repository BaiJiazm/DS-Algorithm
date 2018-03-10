class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>path;
			sort(nums.begin(),nums.end());
			solve(ans,nums,path,0);
			return ans;
		}
		void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&path,int index) {
			if (index>=nums.size()) {
				ans.push_back(path);
				return ;
			}
			for(int i=index; i<nums.size(); ++i)
				if(i==index||nums[i]!=nums[i-1]) {
					path.push_back(nums[i]);
					solve(ans,nums,path,i+1);
					path.pop_back();
				}
			solve(ans,nums,path,nums.size());
		}
};

/*上面的修改写法，这道题明明跟 39. Combination Sum/40. Combination Sum II,46. Permutations/47. Permutations II是一样类型的题目，但是还卡了一会儿，
做了前面四道题目，心想套路是一样的，但是卡在了对结果的思考！前面两者的记录答案的触发条件是达到结果值，而求不同子集记录结果是每次均是答案。 
*/ 
class Solution {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			vector<vector<int>>ans;
			vector<int>path;
			sort(nums.begin(),nums.end());
			solve(ans,nums,path,0);
			return ans;
		}
		void solve(vector<vector<int>>&ans,vector<int>&nums,vector<int>&path,int index) {
			ans.push_back(path);
			for(int i=index; i<nums.size(); ++i)
				if(i==index||nums[i]!=nums[i-1]) {
					path.push_back(nums[i]);
					solve(ans,nums,path,i+1);
					path.pop_back();
				}
		}
};
