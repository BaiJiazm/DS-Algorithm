class Solution {
	public:
		int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
#define NMAX 100
#define INF 0x3f3f3f3f
			int dp[NMAX][NMAX];
			int ndp[NMAX][NMAX];
			int origin[NMAX][NMAX];
			memset(dp, 0x3f, sizeof(dp));
			int i, j, k;
			for (i=0; i<flights.size(); ++i) {
				vector<int>&v=flights[i];
				dp[v[0]][v[1]]=v[2];
			}
			for (i=0; i<n; ++i) {
				dp[i][i]=0;
			}
			memcpy(origin, dp, sizeof(dp));
			int t;
			for (k=0; k<K; ++k) {
				for(i=0; i<n; ++i) {
					for (j=0; j<n; ++j) {
						ndp[i][j]=dp[i][j];
						for(t=0; t<n; ++t) {
							ndp[i][j]=min(ndp[i][j], origin[i][t]+dp[t][j]);
						}
					}
				}
				swap(dp, ndp);
			}
			return dp[src][dst]>=INF?-1:dp[src][dst];
		}
};
