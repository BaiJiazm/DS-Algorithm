/*
�����뵽��������ö�̬�滮�ķ����������
1��dp[l][r][k]��ʾ����[l,r]�ڣ����ַ�k+'a'��β�Ļ��������и�����
��k+'a'==S[l]==S[r]��ʱ�����ǿ������������
1)��l,r���ӽ�����dp[l+1][r-1][k']��k'����[0,3];
2)��l,r�ӽ�����sigma(dp[l+1][r-1][k'])+2������0<=k'<=3��
����Ҫ���ǲ��ظ��������۲����׷��ֵ�1)�����ǡ�ûᱻ��2)��������������������ǿ��Եó����ս��ۣ�dp[l][r][k]=sigma(dp[l+1][r-][k']+2)��0<=k'<=3��(�����ת�ƴ���������)
*/

//const int mod=1e9+7;
//class Solution {
//	public:
//		int dfs(int l,int r,int k,string& S,vector<vector<vector<int> > >& dp) {
//			if(r<l)
//				return 0;
//			if(l==r)
//				return (k==S[l]-'a')?1:0;
//			if(dp[l][r][k]>=0)
//				return dp[l][r][k];
//			int& res=dp[l][r][k]=0;
//			if(r-l==1) {
//				if(S[l]==S[r]&&k==S[l]-'a')
//					return res=2;
//				if(k==S[l]-'a'||k==S[r]-'a')
//					return res=1;
//				return res=0;
//			}
//			if(S[l]==S[r]&&S[l]-'a'==k) {
//				res=2;
//				for(int i=0; i<4; i++) {
//					res+=dfs(l+1,r-1,i,S,dp);
//					res%=mod;
//				}
//			} else {
//				if(S[l]-'a'==k) {
//					res=dfs(l,r-1,k,S,dp);
//				} else {
//					res=dfs(l+1,r,k,S,dp);
//				}
//			}
//			return res;
//		}
//
//		int countPalindromicSubsequences(string S) {
//			int n=S.length();
//			vector<vector<vector<int> > > dp(n,vector<vector<int> >(n,vector<int>(4,-1)));
//			int ans=0;
//			for(int i=0; i<4; i++) {
//				ans+=dfs(0,n-1,i,S,dp);
//				ans%=mod;
//			}
//			return ans;
//		}
//};


/*
	���������ǵݹ�DPд����ע��dp���鲻Ҫ���������棬�����ջ�ռ䲻�㡣 ����vector���档 
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int NMAX=1000;
const int MOD=1e9+7;
int dp[4][NMAX][NMAX];
class Solution {
	public:
		int countPalindromicSubsequences(string S) {
			memset(dp, 0, sizeof(dp));
			int slen=S.length();
			int i, j, k, t;
			int ich, jch;
			for (j=0; j<slen; ++j) {
				for (i=j; i>=0; --i) {
					ich=S[i]-'a';
					jch=S[j]-'a';
//					cout<<i<<", "<<j<<endl;
					for (k=0; k<4; ++k) {
						if(i==j) {
							dp[ich][i][j]=1;
						} else if(k==jch) {
							if(ich==jch) {
								int tem=2;
								for(t=0; t<4; ++t) {
									tem+=dp[t][i+1][j-1];
									tem%=MOD;
								}
								dp[k][i][j]=tem;
							} else {
								dp[k][i][j]=dp[k][i+1][j];
							}
						} else {
							dp[k][i][j]=dp[k][i][j-1];
						}
					}
				}
			}
			int ans=0;
			for (k=0; k<4; ++k) {
				ans+=dp[k][0][slen-1];
				ans%=MOD;
			}
			return ans;
		}
};

int main() {
	Solution s;
	cout<<s.countPalindromicSubsequences("bccb");
	return 0;
}
