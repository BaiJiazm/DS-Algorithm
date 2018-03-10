/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	public:
		vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>>ans;
			if(root==NULL)
				return ans;
			queue<TreeNode*>q;
			q.push(root);
			int size;
			while(!q.empty()) {
				size=q.size();
				vector<int>temv;
				while(size--) {
					TreeNode *pt=q.front();
					q.pop();
					temv.push_back(pt->val);
					if (pt->left)
						q.push(pt->left);
					if (pt->right)
						q.push(pt->right);
				}
				ans.push_back(temv);
			}
			return ans;
		}
};
