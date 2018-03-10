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

//自己写的，复杂度O(n),3ms
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int dp = 0;
		int size = A.size();
		int p, q;
		for (p = 0, q = 1; q<size;)
			if (p + 1 >= q)
				++q;
			else {
				if (A[q] + A[q - 2] == A[q - 1] << 1)
					dp += q - p - 1;
				else
					p = q - 1;
				++q;
			}
			return dp;
	}
};

//改进版
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int curr = 0, sum = 0;
		int size = A.size();
		for (int i = 2; i < size; i++)
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
				curr += 1;
				sum += curr;
			}
			else
				curr = 0;
		return sum;
	}
};

//Leetcode discuss 区代码，3ms
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n < 3) return 0;
		vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i]
		if (A[2] - A[1] == A[1] - A[0]) dp[2] = 1; // if the first three numbers are arithmetic or not
		int result = dp[2];
		for (int i = 3; i < n; ++i) {
			// if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
			// equals to:
			//      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
			//      +
			//      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
			// it is how dp[i] = dp[i-1] + 1 comes
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				dp[i] = dp[i - 1] + 1;
			result += dp[i]; // accumulate all valid slices
		}
		return result;
	}
};

int main()
{
	vector<int>A({ 0,1 });
	Solution s;
	cout<<s.numberOfArithmeticSlices(A);
	system("pause");
	return 0;
}