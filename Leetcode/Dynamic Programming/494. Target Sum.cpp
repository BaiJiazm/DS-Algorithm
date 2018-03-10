#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*	解法一：转化为一维动态规划 
题目要我们给序列里面的每个元素分配一个符号，使得最后的和等于目标值，那实际上不就变成我们从给定序列中找两个子集 P 和 N，使得 sum(P) - sum(N) = S 且 P + N = nums 了吗？
化简一点就是我们需要找到一个集合 P，使得 sum(P) = S - sum(nums - P)。那我们是不是每次需要求出 sum(P) 和 sum(nums - P) 呢？其实不然，我们考虑化简 sum(P) - sum(N) = S：

sum(P) - sum(N) = S

sum(P) + sum(N) + sum(P) - sum(N) = S + sum(P) + sum(N)

2 * sum(P) = S + sum(nums)

sum(P) = (S + sum(nums)) / 2

也就是说，我们只需要找到一个集合 P，使得 sum(P) 等于(S + sum(nums)) / 2 即可，问题立马变得清晰了起来，这样我们就可以用非常基础的动态规划来解决了
*/
class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < S || ((S + sum) & 0x1) == 1) {
			return 0;
		}
		int target = (S + sum) >> 1;
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (auto num : nums) {
			for (int i = target; i >= num; --i) {
				dp[i] += dp[i - num];
			}
		}
		return dp[target];
	}
};


//解法2：暴力深搜 O(2^n)
class Solution {
public:
	int result;
	int findTargetSumWays(vector<int>& nums, int S) {
		dfs(0, 0, nums, S);
		return result;
	}
	void dfs(int sum, int cnt, vector<int>& nums, int S) {
		if (cnt == nums.size()) {
			if (sum == S)
				result++;
			return;
		}
		dfs(sum + nums[cnt], cnt + 1, nums, S);
		dfs(sum - nums[cnt], cnt + 1, nums, S);
	}
};

int main()
{
	vector<int>nums;
	int i;
	for (i = 0; i < 20; ++i)
		nums.push_back(i);
	Solution sl;
	sl.result = 0;
	cout << sl.findTargetSumWays(nums, 190);
	system("pause");
	return 0;
}