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
		int sumNumbers(TreeNode* root) {
			if (root==NULL) {
				this->ans+=sum;
				return this->ans;
			}
			this->sum=this->sum*10+root->val;
			if (root->left==NULL&&root->right==NULL)
				this->ans+=this->sum;

			if (root->left)
				sumNumbers(root->left);
			if (root->right)
				sumNumbers(root->right);
			this->sum/=10;
			return this->ans;
		}
		int ans;
		int sum;
		Solution () {
			this->ans=this->sum=0;
		}
};
