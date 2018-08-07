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
    int maxPathSum(TreeNode* root, int* pmax=NULL) {
        int left=0, right=0;
        int ans=root->val;
        if(root->left){
            ans=max(ans, maxPathSum(root->left, &left));
        }
        if(root->right){
            ans=max(ans, maxPathSum(root->right, &right));
        }
        ans=max(ans, root->val+left);
        ans=max(ans, root->val+right);
        ans=max(ans, root->val+left+right);
        if(pmax!=NULL){
            *pmax=max(root->val, root->val+max(left, right));
        }
        return ans;
    }
};
