/*
	迭代算法，也可以说是DP算法。
	问题比较简单，一开始没有认真分析，造成不自信，还是要多多练习。
*/ 
class Solution {
	public:
		double knightProbability(int N, int K, int r, int c) {
#define MAXN 25
			double dp[MAXN][MAXN]= {0.0};
			dp[r][c]=1;
			double ans=0;

			const int dir[8][2]= {1, 2,  2, 1,  2, -1, 1, -2, -1, -2,  -2, -1,  -2, 1, -1, 2};
			int i,j,k;
			for (k=0; k<K; ++k) {
				double next[MAXN][MAXN]= {0.0};
				for(i=0; i<N; ++i)
					for (j=0; j<N; ++j) {
						for (int t=0; t<8; ++t) {
							int ni=i+dir[t][0];
							int nj=j+dir[t][1];
							if(ni>=0&&ni<N&&nj>=0&&nj<N)
								next[ni][nj]+=dp[i][j]*1.0/8;
							else
								ans+=dp[i][j]*1.0/8;
						}
					}
				memcpy(dp, next, sizeof(dp));
			}
			return 1.0-ans;
		}
};
