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
		TreeNode* addOneRow(TreeNode* root, int v, int d,int left=1) {
			if(d==1) {
				TreeNode *pt=new TreeNode(0);
				pt->val=v;
				if(left) {
					pt->left=root;
					pt->right=NULL;
				} else {
					pt->left=NULL;
					pt->right=root;
				}
				return pt;
			} else if(root==NULL)
				return NULL;
			root->left=addOneRow(root->left,v,d-1,1);
			root->right=addOneRow(root->right,v,d-1,0);
			return root;
		}
};

class Solution {
	public:
		TreeNode* addOneRow(TreeNode* root, int v, int d) {
			if(d == 0 || d==1) {
				TreeNode* newroot = new TreeNode(v);
				if(d == 1) newroot->left = root;
				else if(d == 0) newroot->right = root;
				return newroot;
			}
			if(root && d>=2) {
				root->left = addOneRow(root->left, v, d>2?d-1:1);
				root->right = addOneRow(root->right, v, d>2?d-1:0);
			}
			return root;
		}
};
