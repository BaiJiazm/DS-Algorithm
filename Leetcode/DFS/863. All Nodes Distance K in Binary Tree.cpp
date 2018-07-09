#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    TreeNode* parent[510];
    bool isVisited[510];

  public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
    {
        memset(parent, 0, sizeof(parent));
        markParent(root);
        memset(isVisited, 0, sizeof(isVisited));
        vector<int> ans;
        dfs(target, 0, ans, K);
        return ans;
    }

    void markParent(TreeNode *r)
    {
        if (r == NULL)
        {
            return;
        }
        TreeNode *pLeft = r->left;
        TreeNode *pRight = r->right;
        if (pLeft)
        {
            parent[pLeft->val] = r;
            markParent(pLeft);
        }
        if (pRight)
        {
            parent[pRight->val] = r;
            markParent(pRight);
        }
    }

    void dfs(TreeNode *r, int depth, vector<int> &ans, int K)
    {
        if (r == NULL || isVisited[r->val])
        {
            return;
        }
        isVisited[r->val] = true;
        if (depth == K)
        {
            ans.push_back(r->val);
        }
        dfs(r->left, depth + 1, ans, K);
        dfs(r->right, depth + 1, ans, K);
        dfs(parent[r->val], depth + 1, ans, K);
    }
};
