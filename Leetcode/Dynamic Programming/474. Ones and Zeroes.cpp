#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

/*注解：
	解题思路：一开始很自然的想到了贪心，就是将字符串按长度从短到长排序，然后将m个0，n个1进行分配，但是这样的贪心性质是不成立的，
	因为加入有111, 1100, 0011，m = 4，n = 4，这样的话，只有得出结果为1，显然是不对的。
	那么它要求最多有多少个，可以转化为动态规划中的0 - 1背包问题，
	dp[i][j][k]代表的是前i个字符串1的个数为j0的个数为k的最多字符串个数，那么按照0 - 1背包的思想就是对第i个字符串，我可以采取取也可以采取不取的做法，
	那么转移方程为dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - ones][k - zeros]), 
	又因为i只与i - 1有关，那么可以变为二维数组dp[i][j] = max(dp[i][j], dp[i – a][j – b] + 1).
	dp[m][n]就是结果。注意遍历的时候是从最右底部开始遍历，这样用到的信息就是原来的，不是现在覆盖的了.
*/

class Solution {
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		//这里选最多，也可以转化为0,1背包来做
		vector<vector<int> >dp(m + 1, vector<int>(n + 1, 0));
		int len = strs.size();
		int i, j;

		for (i = 0; i < len; i++) {
			int zeros = 0, ones = 0;
			string temp = strs[i];
			for (j = 0; j < temp.length(); j++)
				temp[j] == '1' ? ones++ : zeros++;
			//有一个处理边界就是m小于zeros个数或者w小于ones个数怎么办
			//printf("%d,%d\n",m,n);
			for (int k = m; k >= zeros; k--) //一定要逆向走
			{
				for (int w = n; w >= ones; w--) //这是从右底部一直走
				{
					//这个dp[k][w]实际上是dp[i-1][k][w]就是没有选择第i个
					dp[k][w] = max(dp[k][w], dp[k - zeros][w - ones] + 1); //这个dp代表数量
				}
			}
		}
		return dp[m][n];
	}
};