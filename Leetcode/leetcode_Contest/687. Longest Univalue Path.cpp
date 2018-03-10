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
		int ans;
		int helper(TreeNode *r) {
			if(r==NULL)
				return 0;
			int llen=1, rlen=1;
			int lret=helper(r->left);
			int rret=helper(r->right);

			if(r->left) {
				llen+=(r->left->val==r->val ? lret: 0);
			}
			if(r->right) {
				rlen+=(r->right->val==r->val ? rret : 0);
			}
			if(r->left&&r->right&&r->val==r->left->val&&r->val==r->right->val) {
				ans=max(ans, llen+rlen-1);
			}
			int ret=max(llen, rlen);
			ans=max(ans, ret);
			return ret;
		}

		int longestUnivaluePath(TreeNode* root) {
			ans=0;
			helper(root);
			return max(ans-1, 0);
		}
};
