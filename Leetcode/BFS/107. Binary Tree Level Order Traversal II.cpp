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
		vector<vector<int> > res;

		void DFS(TreeNode* root, int level) {
			if (root == NULL) return;
			if (level == res.size()) { // The level does not exist in output
				res.push_back(vector<int>()); // Create a new level
			}

			res[level].push_back(root->val); // Add the current value to its level
			DFS(root->left, level+1); // Go to the next level
			DFS(root->right,level+1);
		}

		vector<vector<int> > levelOrderBottom(TreeNode *root) {
			DFS(root, 0);
			return vector<vector<int> > (res.rbegin(), res.rend());
		}
};
