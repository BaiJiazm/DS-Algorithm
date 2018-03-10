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
		bool isSymmetric(TreeNode* root) {
			if(!root)
				return true;
			return isSyme(root->left,root->right);
		}
	private:
		bool isSyme(TreeNode*r1,TreeNode*r2) {
			if (r1==NULL&&r2==NULL)
				return true;
			else if (r1==NULL&&r2||r1&&r2==NULL)
				return false;
			else {
				if(r1->val==r2->val)
					if (isSyme(r1->left,r2->right)&&isSyme(r1->right,r2->left))
						return true;
				return false;
			}
		}
};
