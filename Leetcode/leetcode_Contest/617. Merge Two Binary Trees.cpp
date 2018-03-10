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
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if(t1==NULL&&t2==NULL)
				return NULL;
			else if(t1==NULL&&t2!=NULL)
				return t2;
			else if(t2==NULL&&t1!=NULL)
				return t1;
			t1->val+=t2->val;
			t1->left=mergeTrees(t1->left,t2->left);
			t1->right=mergeTrees(t1->right,t2->right);
			return t1;
		}
};

class Solution {
	public:
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if (!t1) return t2;
			if (!t2) return t1;

			TreeNode* node = new TreeNode(t1->val + t2->val);
			node->left = mergeTrees(t1->left, t2->left);
			node->right = mergeTrees(t1->right, t2->right);
			return node;
		}
};


//考虑到内存的释放，此为最正确的答案。
class Solution {
	public:
		TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
			if (!t1 && !t2) {
				return nullptr;
			}
			TreeNode* node = new TreeNode((t1 ? t1->val : 0) + (t2 ? t2->val : 0));
			node->left = mergeTrees((t1 ? t1->left : nullptr), (t2 ? t2->left : nullptr));
			node->right = mergeTrees((t1 ? t1->right : nullptr), (t2 ? t2->right : nullptr));
			return node;
		}
};
