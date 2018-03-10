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
		int findBottomLeftValue(TreeNode* root) {
			queue<TreeNode*>q;
			q.push(root);
			int leftValue=0;
			int size=root?1:0;
			while(size) {
				for (int i=0; i<size; ++i) {
					TreeNode *ptr=q.front();
					q.pop();
					if (!i)
						leftValue=ptr->val;
					if (ptr->left)
						q.push(ptr->left);
					if (ptr->right)
						q.push(ptr->right);
				}
				size=q.size();
			}
			return leftValue;
		}
};
