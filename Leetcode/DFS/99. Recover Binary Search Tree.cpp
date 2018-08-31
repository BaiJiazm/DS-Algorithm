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
		TreeNode* pre, *p1, *p2;
		int preVal=INT_MIN;
		void recoverTree(TreeNode* root) {
			pre=p1=p2=NULL;
			inOrderTraverse(root);
			p1->val^=p2->val;
			p2->val^=p1->val;
			p1->val^=p2->val;
		}
		void inOrderTraverse(TreeNode* root) {
			if(root==NULL)
				return ;
			inOrderTraverse(root->left);
			if(preVal>root->val) {
				if(p1==NULL)
					p1=pre, p2=root;
				else
					p2=root;
			}
			pre=root;
			preVal=root->val;
			inOrderTraverse(root->right);
		}
};
