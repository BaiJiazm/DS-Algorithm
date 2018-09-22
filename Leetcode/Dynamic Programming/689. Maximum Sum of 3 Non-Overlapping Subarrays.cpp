/*
	真是有几个月没有刷题，然后解题速度就下降了，但是关键的还是心态问题，比如这周的题目应该都挺简单的，
	但是就是做的慢，加油！
	下面是leetcode Discuss区优质解答。 
	C++/Java, DP with explanation, O(n)
	The question asks for three non-overlapping intervals with maximum sum of all 3 intervals. If the middle interval is [i, i+k-1], where k <= i <= n-2k, the left interval has to be in subrange [0, i-1], and the right interval is from subrange [i+k, n-1].

	So the following solution is based on DP.

	posLeft[i] is the starting index for the left interval in range [0, i];
	posRight[i] is the starting index for the right interval in range [i, n-1];
	Then we test every possible starting index of middle interval, i.e. k <= i <= n-2k, and we can get the corresponding left and right max sum intervals easily from DP. And the run time is O(n).
*/
class Solution {
	public:
		vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
			int n = nums.size(), maxsum = 0;
			vector<int> sum = {0}, posLeft(n, 0), posRight(n, n-k), ans(3, 0);
			for (int i:nums) sum.push_back(sum.back()+i);
			// DP for starting index of the left max sum interval
			for (int i = k, tot = sum[k]-sum[0]; i < n; i++) {
				if (sum[i+1]-sum[i+1-k] > tot) {
					posLeft[i] = i+1-k;
					tot = sum[i+1]-sum[i+1-k];
				} else
					posLeft[i] = posLeft[i-1];
			}
			// DP for starting index of the right max sum interval
			for (int i = n-k-1, tot = sum[n]-sum[n-k]; i >= 0; i--) {
				if (sum[i+k]-sum[i] > tot) {
					posRight[i] = i;
					tot = sum[i+k]-sum[i];
				} else
					posRight[i] = posRight[i+1];
			}
			// test all possible middle interval
			for (int i = k; i <= n-2*k; i++) {
				int l = posLeft[i-1], r = posRight[i+k];
				int tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
				if (tot > maxsum) {
					maxsum = tot;
					ans = {l, i, r};
				}
			}
			return ans;
		}
};
