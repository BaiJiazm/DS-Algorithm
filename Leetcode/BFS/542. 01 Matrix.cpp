class Solution {
	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
			int h=matrix.size(), w=matrix[0].size();
			vector<vector<int>> dp(h,vector<int>(w,INT_MAX));
			for(int times=0; times<=1; times++) // two passes, first forward then backward
				for(int i=times?h-1:0; times?i>=0:i<h; times?i--:i++)
					for(int j=times?w-1:0; times?j>=0:j<w; times?j--:j++)
						if(matrix[i][j]==0)
							dp[i][j]=0;
						else {
							if(i&&dp[i-1][j]!=INT_MAX&&dp[i][j]>dp[i-1][j]+1) // look up
								dp[i][j]=dp[i-1][j]+1;
							if(j&&dp[i][j-1]!=INT_MAX&&dp[i][j]>dp[i][j-1]+1) // look left
								dp[i][j]=dp[i][j-1]+1;
							if(i<h-1&&dp[i+1][j]!=INT_MAX&&dp[i][j]>dp[i+1][j]+1) // look down
								dp[i][j]=dp[i+1][j]+1;
							if(j<w-1&&dp[i][j+1]!=INT_MAX&&dp[i][j]>dp[i][j+1]+1) // look right
								dp[i][j]=dp[i][j+1]+1;
						}
			return dp;
		}
};


class Solution {
	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
			int n = matrix.size(), m = matrix.front().size();
			vector<vector<int>> res(n, vector<int>(m, 20000));

			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (matrix[i][j] == 0)
						res[i][j] = 0;
					else {
						if (i > 0)
							res[i][j] = res[i - 1][j] + 1;
						if (j > 0)
							res[i][j] = min(res[i][j], res[i][j - 1] + 1);
					}

			for (int i = n - 1; i >= 0; i--)
				for (int j = m - 1; j >= 0; j--) {
					if (i < n - 1)
						res[i][j] = min(res[i][j], res[i + 1][j] + 1);
					if (j < m - 1)
						res[i][j] = min(res[i][j], res[i][j + 1] + 1);
				}

			return res;
		}
};


class Solution {
	public:
		vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
			vector<pair<int, int> > dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

			queue<pair<int, int> > q;
			for(int i=0; i<matrix.size(); i++) {
				for(int j=0; j<matrix[0].size(); j++) {
					if(matrix[i][j] == 0) {
						q.push({i, j});
					} else {
						matrix[i][j] = 10001;
					}
				}
			}
			while(q.size()) {
				pair<int, int> n;
				n = q.front();
				q.pop();
				int i, j, k;
				i = n.first;
				j = n.second;
				//four direction
				for(vector<pair<int, int> >::iterator it=dir.begin(); it!=dir.end(); it++) {
					int ii = i + it->first;
					int jj = j + it->second;
					if(ii>=0 && ii<matrix.size() && jj>=0 && jj<matrix[0].size()) {
						if(matrix[ii][jj] > matrix[i][j] + 1) {
							matrix[ii][jj] = matrix[i][j] + 1;
							q.push({ii, jj});
						}
					}
				}

			}
			return matrix;
		}
};
