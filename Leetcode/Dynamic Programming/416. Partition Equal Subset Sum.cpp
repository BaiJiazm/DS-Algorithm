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

//膜大神，流弊，四行完事且效率高
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		const int MAX_NUM = 100;
		const int MAX_ARRAY_SIZE = 200;
		bitset<MAX_NUM * MAX_ARRAY_SIZE / 2 + 1> bits(1);
		int sum = 0;
		for (auto n : nums) {
			sum += n;
			bits |= bits << n;
		}
		return !(sum % 2) && bits[sum / 2];
	}
};

//最初版，注意题目有更改，10001改下就是
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		bitset<10001> bits(1);
		int sum = accumulate(nums.begin(), nums.end(), 0);
		for (auto n : nums) bits |= bits << n;
		return !(sum & 1) && bits[sum >> 1];
	}
};


//自己写的代码，最初还写错了，注意要从后向前更新
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % 2)
			return false;
		int mid = sum / 2;
		vector<bool>dp(mid + 1, false);
		int size = nums.size();
		int i, j, n;
		dp[0] = true;
		for (i = 0; i < size; ++i) {
			n = nums[i];
			for (j = mid - n; j >= 0; --j)
				if (dp[j])
					dp[j + n] = true;
			if (dp[mid])
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int>nums = { 2,2,3,5 };
	Solution s;
	cout<<s.canPartition(nums);
	system("pause");
	return 0;
}