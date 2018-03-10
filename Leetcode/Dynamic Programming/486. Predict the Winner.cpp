#include<vector>
#include<algorithm>
using namespace std;

//解法一：递归型DP
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		this->nums = nums;
		int len = nums.size();
		dp.resize(len, vector<int>(len, 0));
		return fun(0, len - 1) >= 0;
	}
private:
	vector<int>nums;
	vector<vector<int>>dp;
	int fun(int begin, int end) {
		return dp[begin][end] = begin == end ? nums[begin] : max(nums[begin] - fun(begin + 1, end), nums[end] - fun(begin, end - 1));
	}
};

//解法二：直接DP
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>>dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; ++i) {
			dp[i][i] = nums[i];
			for (int j = i - 1; j >= 0; --j)
				dp[j][i] = max(nums[i] - dp[j][i - 1], nums[j] - dp[j + 1][i]);
		}
		return dp[0][len - 1] >= 0;
	}
};

//解法三：递归模拟
class Solution {
public:
	bool PredictTheWinner(vector<int>& nums) {
		return first(nums, 0, nums.size() - 1, 0, 0);
	}
private:
	bool first(const vector<int>& nums, int l, int r, int s1, int s2) {
		if (l > r) {
			return s1 >= s2;
		}
		return !second(nums, l + 1, r, s1 + nums[l], s2) || !second(nums, l, r - 1, s1 + nums[r], s2);
	}
	bool second(const vector<int>& nums, int l, int r, int s1, int s2) {
		if (l > r) {
			return s1 < s2;
		}
		return !first(nums, l + 1, r, s1, s2 + nums[l]) || !first(nums, l, r - 1, s1, s2 + nums[r]);
	}
};