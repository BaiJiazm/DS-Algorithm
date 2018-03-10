class Solution {
	public:
		/**
		* Taking 1~n as root respectively:
		*      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
		*      2 as root: # of trees = F(1) * F(n-2)
		*      3 as root: # of trees = F(2) * F(n-3)
		*      ...
		*      n-1 as root: # of trees = F(n-2) * F(1)
		*      n as root:   # of trees = F(n-1) * F(0)
		*
		* So, the formulation is:
		*      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
		*/

		int numTrees(int n) {
			int dp[n+1];
			dp[0] = dp[1] = 1;
			for (int i=2; i<=n; i++) {
				dp[i] = 0;
				for (int j=1; j<=i; j++) {
					dp[i] += dp[j-1] * dp[i-j];
				}
			}
			return dp[n];
		}
};
