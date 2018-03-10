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
		int findTilt(TreeNode* root) {
			int s=0;
			return helpFindTilt(root,s);
		}
		int helpFindTilt(TreeNode* root,int &sum){
			if(root==NULL){
				sum=0;
				return 0;
			}
			int l,r,tilt;
			tilt=helpFindTilt(root->left,l);
			tilt+=helpFindTilt(root->right,r);
			tilt+=abs(l-r);
			sum=l+r+root->val;
			return tilt;
		}
};
