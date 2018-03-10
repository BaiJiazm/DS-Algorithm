#include <vector>
#include <algorithm>
using namespace std;
//题目分析：
//
//零钱对换，用最少的零钱数，换取目标的数量。
//
//解题思路：
//
//动态规划求解
//
//1）dp[i]表示对换目标i所需的最少硬币数目；
//
//2）计算过程中的动态规划公式为dp[i + coins[j]] = min(dp[i + coins[j], dp[i] + 1)。
//
//实现程序
//
//C++版本

// CPP  
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) {
			return 0;
		}
		// 初始化数组为 0，并将已有钱数置为 1   
		// initialized vector f with 0 then fill the coin value as 1  
		vector<int> f(amount + 1, 0);
		for (int i = 0; i < coins.size(); ++i) {
			if (coins[i] <= amount) {
				f[coins[i]] = 1;
			}
		}
		// 在能够凑出钱数目的基础上，计算出新的可凑出的钱数，并更新其需要的张数   
		// for every value which can be added up to, calculate new value and refresh new value's times  
		for (int pos = 0; pos <= amount; ++pos) {
			if (f[pos] == 0) {
				continue;
			}
			for (int i = 0; i < coins.size(); ++i) {
				int value = pos + coins[i];
				if (value <= amount) {
					f[value] = (f[value] == 0) ?
						(f[pos] + 1) : min(f[value], f[pos] + 1);
				}
			}
		}
		return (f[amount] == 0) ? -1 : f[amount];
	}
};  //Java版本
//
//public int coinChange(int[] coins, int amount) {
//	int[] dp = new int[amount + 1];
//	final int INF = 0x7ffffffe;
//	// 初始化dp[i]数组，注意从1开始初始化
//	for (int i = 0; i <= amount; i++)
//		dp[i] = INF;
//	dp[0] = 1;
//	// 动态规划进行求解
//	for (int i = 0; i <= amount; i++) {
//		for (int j = 0; j < coins.length; j++) {
//			if (i + coins[j] <= amount)
//				dp[i + coins[j]] = Math.min(dp[i + coins[j]], dp[i] + 1);
//		}
//	}
//	return dp[amount] == INF ? -1 : dp[amount];
//}