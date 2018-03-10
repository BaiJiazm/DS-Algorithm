/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //自己写的，不是特别简洁   time:12ms
class Solution {
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			if (root==NULL)
				return vector<vector<int>>();
			pSum=0;
			this->sum=sum;
			dfs(root);
			return ans;
		}
		vector<vector<int> >ans;
		vector<int>path;
		int pSum;
		int sum;
		void dfs(TreeNode*&r) {
			if (r->left==NULL&&r->right==NULL) {
				if (pSum+r->val==sum) {
					path.push_back(r->val);
					ans.push_back(path);
					path.pop_back();
				}
				return ;
			}
			pSum+=r->val;
			path.push_back(r->val);
			if(r->left)
				dfs(r->left);
			if (r->right)
				dfs(r->right);
			pSum-=r->val;
			path.pop_back();
		}
};

//一般写法  time:9ms
class Solution {
	public:
		vector<vector<int>> pathSum(TreeNode* root, int sum) {
			vector<vector<int> > paths;
			vector<int> path;
			findPaths(root, sum, path, paths);
			return paths;
		}
	private:
		void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
			if (!node) return;
			path.push_back(node -> val);
			if (!(node -> left) && !(node -> right) && sum == node -> val)
				paths.push_back(path);
			findPaths(node -> left, sum - node -> val, path, paths);
			findPaths(node -> right, sum - node -> val, path, paths);
			path.pop_back();
		}
};
