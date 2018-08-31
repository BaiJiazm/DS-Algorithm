//https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization
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
		vector<int> postorderTraversal(TreeNode* root) {
			vector<int> nodes;
			stack<TreeNode*> todo;
			TreeNode* cur = root;
			TreeNode* last = NULL;
			while (cur || !todo.empty()) {
				if (cur) {
					todo.push(cur);
					cur = cur -> left;
				} else {
					TreeNode* top = todo.top();
					if (top -> right && (last != top -> right)) {
						cur = top -> right;
					} else {
						nodes.push_back(top -> val);
						last = top;
						todo.pop();
					}
				}
			}
			return nodes;
		}
};
