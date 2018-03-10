#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
    这道题是动态规划的经典题目，曾经看到过，time:52ms
*/
class Solution {
	public:
		int longestIncreasingPath(vector<vector<int> >& matrix) {
			if (matrix.size()==0||matrix[0].size()==0)
				return 0;

			int row=matrix.size();
			int col=matrix[0].size();
			int maxRowCol=max(row,col);
			vector< pair<int,int> >posVec;
			vector< vector<int> >longestIncrease(row,vector<int>(col,1));
			for (int i=0; i<row; ++i) {
				for (int j=0; j<col; ++j)
					posVec.push_back({matrix[i][j],i*maxRowCol+j});
			}
			sort(posVec.begin(),posVec.end());
			int ans=0;
			for (int i=0; i<posVec.size(); ++i) {
				int th=posVec[i].first;
				int tr=posVec[i].second/maxRowCol;
				int tc=posVec[i].second%maxRowCol;
				if (tr>0&&th>matrix[tr-1][tc])
					longestIncrease[tr][tc]=max(longestIncrease[tr][tc],longestIncrease[tr-1][tc]+1);
				if (tr<row-1&&th>matrix[tr+1][tc])
					longestIncrease[tr][tc]=max(longestIncrease[tr][tc],longestIncrease[tr+1][tc]+1);
				if (tc>0&&th>matrix[tr][tc-1])
					longestIncrease[tr][tc]=max(longestIncrease[tr][tc],longestIncrease[tr][tc-1]+1);
				if (tc<col-1&&th>matrix[tr][tc+1])
					longestIncrease[tr][tc]=max(longestIncrease[tr][tc],longestIncrease[tr][tc+1]+1);
				ans=max(ans,longestIncrease[tr][tc]);
			}
			return ans;
		}
};

int main() {
	vector<vector<int> >matrix(3);
	matrix[0]= {9,9,4};
	matrix[1]= {6,6,8};
	matrix[2]= {2,1,1};
	Solution s;
	cout<<s.longestIncreasingPath(matrix)<<endl;
	return 0;
}

/*
	dfs递归搜索 time:129ms
*/
class Solution {
	public:
		int longestIncreasingPath(vector<vector<int> >& matrix) {
			if (matrix.empty() || matrix[0].empty()) return 0;
			int res = 1, m = matrix.size(), n = matrix[0].size();
			vector<vector<int> > dp(m, vector<int>(n, 0));
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					res = max(res, dfs(matrix, dp, i, j));
				}
			}
			return res;
		}
		int dfs(vector<vector<int> > &matrix, vector<vector<int> > &dp, int i, int j) {
			if (dp[i][j]) return dp[i][j];
			vector<vector<int> > dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
			int mx = 1, m = matrix.size(), n = matrix[0].size();
			for (auto a : dirs) {
				int x = i + a[0], y = j + a[1];
				if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
				int len = 1 + dfs(matrix, dp, x, y);
				mx = max(mx, len);
			}
			dp[i][j] = mx;
			return mx;
		}
};
