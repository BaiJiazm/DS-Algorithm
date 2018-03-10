class Solution {
	public:
		vector<vector<int>> combinationSum3(int k, int n) {
			vector<vector<int>>ans;
			vector<int>tem;
			solve(ans,tem,k,n,1);
			return ans;
		}
		void solve(vector<vector<int>>&ans, vector<int>&tem,int k,int n,int s) {
			if (n==0&&k==0) {
				ans.push_back(tem);
				return ;
			} else if (k<=0||n<=0)
				return ;
			for (; s<10; ++s) {
				tem.push_back(s);
				solve(ans,tem,k-1,n-s,s+1);
				tem.pop_back();
			}
		}
};
