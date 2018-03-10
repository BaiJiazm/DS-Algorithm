#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

/*	�ⷨһ��ת��Ϊһά��̬�滮 
��ĿҪ���Ǹ����������ÿ��Ԫ�ط���һ�����ţ�ʹ�����ĺ͵���Ŀ��ֵ����ʵ���ϲ��ͱ�����ǴӸ����������������Ӽ� P �� N��ʹ�� sum(P) - sum(N) = S �� P + N = nums ����
����һ�����������Ҫ�ҵ�һ������ P��ʹ�� sum(P) = S - sum(nums - P)���������ǲ���ÿ����Ҫ��� sum(P) �� sum(nums - P) �أ���ʵ��Ȼ�����ǿ��ǻ��� sum(P) - sum(N) = S��

sum(P) - sum(N) = S

sum(P) + sum(N) + sum(P) - sum(N) = S + sum(P) + sum(N)

2 * sum(P) = S + sum(nums)

sum(P) = (S + sum(nums)) / 2

Ҳ����˵������ֻ��Ҫ�ҵ�һ������ P��ʹ�� sum(P) ����(S + sum(nums)) / 2 ���ɣ������������������������������ǾͿ����÷ǳ������Ķ�̬�滮�������
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


//�ⷨ2���������� O(2^n)
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