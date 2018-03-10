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
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (target <= 0)
			return 0;

		vector<int>dp(target + 1, 0);
		int size = nums.size();
		int i, j, t;
		dp[0] = 1;
		for (j = 1; j <= target; ++j)
			for (i = 0; i < size; ++i)
				if ((t = j - nums[i]) >= 0)
					dp[j] += dp[t];
		return dp[target];
	}
};

int main()
{
	vector<int>nums({ 1,2,3 });
	Solution s;
	cout << s.combinationSum4(nums, 4);
	system("pause");
	return 0;
}