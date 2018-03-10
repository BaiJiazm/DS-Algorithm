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
		int rob(TreeNode* root) {
			int v1,v2;
			stole(root,v1,v2);
			return max(v1,v2);
		}
	private:
		//v1:偷 v2:不偷
		void stole(TreeNode *&root,int &v1,int &v2) {
			if (root==NULL) {
				v1=v2=0;
				return ;
			}
			int lv1,lv2;
			int rv1,rv2;
			stole(root->left,lv1,lv2);
			stole(root->right,rv1,rv2);

			v1=root->val+lv2+rv2;
			//错误写法如下：因为root节点不偷，其孩子节点即可以偷，也可以不偷！
			//v2=lv1+rv1;
			v2=max(lv1,lv2)+max(rv1,rv2);
			return ;
		}
};
