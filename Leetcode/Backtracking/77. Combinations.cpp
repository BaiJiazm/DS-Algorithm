class Solution {
	public:
		vector<vector<int>> combine(int n, int k) {
			vector<vector<int>>res;
			vector<int>path;
			dfs(res,path,n,k);
			return res;
		}
		void dfs(vector<vector<int>>&res,vector<int>&path,int n,int k) {
			if(k<=0) {
				res.push_back(path);
				return ;
			}
			if(n<k)
				return ;
			for(; n>0; --n) {
				path.push_back(n);
				dfs(res,path,n-1,k-1);
				path.pop_back();
			}
		}
};
