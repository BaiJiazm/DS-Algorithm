#include "headFile"

/*
	此题目应该是一类经典暴力需n!的题目中的典型。
	一般暴力穷举结果需要n!的此类题目，一般都可以用DP算法n^3解决，类似题目还有前面的某个题目（题号忘记了）以及CCF的压缩编码，石子游戏等题目类似。
	不过这个题目应该说更为一般。其他类似题目的子问题都可以分开考虑，但是这道题目有点不一样，其实从某种角度来看，是一样的。看怎么去理解！

	思考方式一般有两种：
		1.自底向上（从简单的子问题考虑，递推迭代到最终解）（此题的子问题容易被误解。nums[i]应该和两边1的作用等价）
		2.自顶向下（从最后的问题出发，思考如果小规模的相同性质问题解决后，此问题可以如何得到解决。）

    一般说来，两种方式都不是独立存在的，应该是相辅相成的，共同思考的。

    这类题的写法有三种：
		1.从左到右的三角形
		2.从右到左的三角形
		3.从斜边到直角的三角形

*/

//写法一：从斜边到直角的三角形
class Solution {
	public:
		int maxCoins(vector<int>& nums) {
			int size=nums.size();
			if (size==0)
				return 0;
			nums.insert(nums.begin(),1);
			nums.insert(nums.end(),1);
			vector<vector<int>>dp(size+2,vector<int>(size+2,0));
			for (int len=1; len<=size; ++len) {
				for (int i=1; i<=size+1-len; ++i) {
					for (int j=i; j<i+len; ++j) {
						dp[i][i+len-1]=max(dp[i][i+len-1],nums[j]*nums[i-1]*nums[i+len]+dp[i][j-1]+dp[j+1][i+len-1]);
					}
				}
			}
			return dp[1][size];
		}
};

//写法二：从左到右的三角形
class Solution {
	public:
		int maxCoins(vector<int>& nums) {
			int size=nums.size();
			if (size==0)
				return 0;
			nums.insert(nums.begin(),1);
			nums.insert(nums.end(),1);
			vector<vector<int>>dp(size+2,vector<int>(size+2,0));
			for(int j=1; j<=size; ++j) {
				for (int i=j; i>0; --i) {
					for (int k=i; k<=j; ++k)
						dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j+1]);
				}
			}
			return dp[1][size];
		}
};
