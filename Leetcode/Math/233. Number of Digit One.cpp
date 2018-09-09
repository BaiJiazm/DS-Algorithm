//纯数学解题，厉害！数学推导题及找规律题目思维还要加强，但是都是套路！
//参照链接，学习推导 
//https://leetcode.com/problems/number-of-digit-one/solution/

class Solution {
	public:
		int countDigitOne(int n) {
			int countr = 0;
			for (long long i = 1; i <= n; i *= 10) {
				long long divider = i * 10;
				countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
			}
			return countr;
		}
};
