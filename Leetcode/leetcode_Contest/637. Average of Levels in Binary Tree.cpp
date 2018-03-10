class Solution {
		vector<long long>sum;
		vector<int>cnt;
		void dfs(TreeNode* root,int level) {
			if(root==NULL)
				return ;
			if(sum.size()>level) {
				sum[level]+=root->val;
				++cnt[level];
			} else {
				sum.push_back(root->val);
				cnt.push_back(1);
			}
			dfs(root->left,level+1);
			dfs(root->right,level+1);
		}
	public:
		vector<double> averageOfLevels(TreeNode* root) {
			dfs(root,0);
			vector<double>ans;
			for(int i=0; i<sum.size(); ++i)
				ans.push_back(sum[i]*1.0/cnt[i]);
			return ans;
		}
};
