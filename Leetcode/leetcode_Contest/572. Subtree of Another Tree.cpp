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
		bool isSame(TreeNode *s,TreeNode*t) {
			if(s==NULL&&t==NULL)
				return true;
			else if(s==NULL&&t!=NULL||s!=NULL&&t==NULL)
				return false;
			else if(s->val!=t->val)
				return false;
			return isSame(s->left,t->left)&&isSame(s->right,t->right);
		}
		bool isSubtree(TreeNode* s, TreeNode* t) {
			if(isSame(s,t))
				return true;
			if(s)
				if(isSubtree(s->left,t)||isSubtree(s->right,t))
					return true;
			return false;
		}
};
