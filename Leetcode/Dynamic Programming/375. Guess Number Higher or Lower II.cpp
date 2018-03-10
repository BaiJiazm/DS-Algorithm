#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>

#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
#include<cmath>
#include<cstring>
using namespace std;

//解法一：自己写的，非递归DP    13ms
class Solution {
	public:
		int getMoneyAmount(int n) {
			vector< vector<int> > dp(n+1,vector<int>(n+1,0));
			int i,j,k;
			for (j=1; j<=n; ++j) {
				for(i=j-1; i; --i) {
					dp[i][j]=j+dp[i][j-1];
					for (k=j-1; k>=i; --k) {
						dp[i][j]=min(dp[i][j],k+max(dp[i][k-1],dp[k+1][j]));
					}
				}
			}
			return dp[1][n];
		}
};

//递归DP 36ms
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		return solve(dp, 1, n);
	}

	int solve(vector<vector<int>> &dp, int L, int R) {
		if (L >= R) return 0;
		if (dp[L][R]) return dp[L][R];
		dp[L][R] = 0x7FFFFFFF;
		for (int i = L; i <= R; i++) {
			dp[L][R] = min(dp[L][R], i + max(solve(dp,L,i-1),solve(dp,i+1,R)));
		}
		return dp[L][R];
	}
};

int main() {
	Solution s;
	cout<<s.getMoneyAmount(5)<<endl;
	return 0;
}
