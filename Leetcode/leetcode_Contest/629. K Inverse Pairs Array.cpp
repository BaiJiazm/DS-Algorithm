#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
	有必要总结一下动规解题规范，明明自己很快知道了思路，但是用了很多时间才ac，究其原因：
	1.	动规写法没有固定化，在一些题目汇总边界条件进行扩大，经初始后编程相对简介，但是有时其意义和题目中定义的有一点点偏差，
		容易出错，此时宜按照意义确定下标较好。
	2.	读题马虎，将mod=1e9+7	看成了1e9+9
	3.	j-i这种反应迟钝，太谨慎。
*/
class Solution {
	public:
		int kInversePairs(int n, int k) {
#define MOD 1000000007
			vector<vector<int>>dp(n+1,vector<int>(k+1,0));
			//下面写法会 Memerry Limit Error !
			//vector<vector<int>>dp(1005,vector<int>(1005,0));

			dp[1][0]=1;
			for(int i=2; i<=n; ++i) {
				dp[i][0]=1;
				int maxk=i*(i-1)>>1;
				for(int j=1; j<=min(k,maxk); ++j) {
					dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD+MOD;
					if(j-i>=0)
						dp[i][j]-=dp[i-1][j-i];
					dp[i][j]%=MOD;
				}
			}
			return dp[n][k];
		}
};

//discuss区解答
//class Solution {
//public:
//    int kInversePairs(int n, int k) {
//        vector<vector<int>> dp(n+1, vector<int>(k+1));
//        dp[0][0] = 1;
//        for(int i = 1; i <= n; ++i){
//            dp[i][0] = 1;
//            for(int j = 1; j <= k; ++j){
//                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
//                if(j - i >= 0){
//                    dp[i][j] = (dp[i][j] - dp[i-1][j-i] + mod) % mod;
//                    //It must + mod, If you don't know why, you can check the case 1000, 1000
//                }
//            }
//        }
//        return dp[n][k];
//    }
//private:
//    const int mod = pow(10, 9) + 7;
//};

int main() {
	Solution s;
	cout<<s.kInversePairs(2,0)<<endl;
	return 0;
}
