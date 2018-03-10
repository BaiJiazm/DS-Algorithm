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
		vector<int> largestValues(TreeNode* root) {
			vector<int>ans;
			if (root==NULL)
				return ans;

			vector<int>levelValues;
			queue<TreeNode*>q1,q2;
			q1.push(root);
			while(!q1.empty()) {
				while(!q1.empty()) {
					TreeNode *ptr=q1.front();
					q1.pop();
					levelValues.push_back(ptr->val);
					if(ptr->left)
						q2.push(ptr->left);
					if (ptr->right)
						q2.push(ptr->right);
				}
				ans.push_back(*max_element(levelValues.begin(),levelValues.end()));
				levelValues.clear();
				swap(q1,q2);
			}
			return ans;
		}
};
