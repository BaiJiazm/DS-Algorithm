///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//	public:
//		int ans;
//		int helper(TreeNode *r) {
//			if(r==NULL)
//				return 0;
//			int llen=1, rlen=1;
//			int lret=helper(r->left);
//			int rret=helper(r->right);
//
//			if(r->left) {
//				llen+=(r->left->val==r->val ? lret: 0);
//			}
//			if(r->right) {
//				rlen+=(r->right->val==r->val ? rret : 0);
//			}
//			if(r->left&&r->right&&r->val==r->left->val&&r->val==r->right->val){
//				ans=max(ans, llen+rlen-1);
//			}
//			int ret=max(llen, rlen);
//			ans=max(ans, ret);
//			return ret;
//		}
//
//		int longestUnivaluePath(TreeNode* root) {
//			ans=0;
//			helper(root);
//			return max(ans-1, 0);
//		}
//};

//class Solution {
//	public:
//		int repeatedStringMatch(string A, string B) {
//			int alen=A.length();
//			int blen=B.length();
//			int i,j,k,ans;
//			for(i=0; i<alen; ++i){
//				if(A[i]==B[0]){
//					ans=1;
//					for(j=0, k=i; j<blen; ++j, ++k){
//						ans+=(k==alen);
//						k=k%alen;
//						if(A[k]!=B[j])
//							break;
//					}
//					if(j==blen)
//						return ans;
//				}
//			}
//			return -1;
//		}
//};

class Solution {
	public:
		double knightProbability(int N, int K, int r, int c) {
			#define MAXN 25
			double dp[MAXN][MAXN]={0.0};
			dp[r][c]=1;
			double ans=0;
			
			const int dir[8][2]={1, 2,  2, 1,  2, -1, 1, -2, -1, -2,  -2, -1,  -2, 1, -1, 2};
			int i,j,k;
			for (k=0;k<K;++k){
				double next[MAXN][MAXN]={0.0};
				for(i=0;i<N;++i)
					for (j=0;j<N;++j){
						for (int t=0;t<8;++t){
							int ni=i+dir[t][0];
							int nj=j+dir[t][1];
							if(ni>=0&&ni<N&&nj>=0&&nj<N)
								next[ni][nj]+=dp[i][j]*1.0/8;
							else
								ans+=dp[i][j]*1.0/8;
						}
					}
				memcpy(dp, next, sizeof(dp));
			}
			return 1.0-ans;
		}
};
