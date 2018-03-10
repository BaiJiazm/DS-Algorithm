#include"headFile"

//�ⷨһ����DP,�������   ʱ�临�Ӷȣ�O(n^2)
class Solution {
	public:
		int integerBreak(int n) {
			vector<int>dp(n+1,0);
			for (int i=2; i<=n; ++i) {
				int left,right;
				for (left=1,right=i-1; left<=right; ++left,--right) {
					dp[i]=max(dp[i],max (left,dp[left])*max (right,dp[right]));
				}
			}
			return dp[n];
		}
};

//�ⷨ����Leetcode Discuss���ⷨ    ʱ�临�Ӷȣ�O(n)
class Solution {
	public:
		long long integerBreak(long long n) {
			if(n == 2) return 1;
			if(n == 3) return 2;
			if(n == 4) return 4;
			if(n == 5) return 6;
			if(n == 6) return 9;
			return 3 * integerBreak(n - 3);
		}
};

//�ⷨ����Leetcode Discuss���ⷨ    ʱ�临�Ӷȣ�O(logn)
class Solution {
	public:
		int integerBreak(int n) {
			if(n == 2)
				return 1;
			else if(n == 3)
				return 2;
			else if(n%3 == 0)
				return (int)pow(3, n/3);
			else if(n%3 == 1)
				return 2 * 2 * (int) pow(3, (n - 4) / 3);
			else
				return 2 * (int) pow(3, n/3);
		}
};


