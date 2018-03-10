#include"headFile"

class Solution {
	public:
		int maximalSquare(vector<vector<char>>& matrix) {
			int maxSquare=0;
			if (matrix.size()==0||matrix[0].size()==0)
				return 0;
			int row=matrix.size(),col=matrix[0].size();

			vector<vector<int>>dp(row+1,vector<int>(col+1,0));
			for (int i=0; i<row; ++i) {
				for (int j=0; j<col; ++j) {
					if (matrix[i][j]-'0') {
						dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
					} else
						dp[i+1][j+1]=0;
					maxSquare=max(maxSquare,dp[i+1][j+1]);
				}
			}
			return  maxSquare*maxSquare;
		}
};



int main() {
	freopen("test.txt","r",stdin);

	vector<vector<char>> matrix(4,vector<char>(5));
	for (int i=0; i<4; ++i)
		for (int j=0; j<5; ++j)
			cin>>matrix[i][j];
	Solution s;
	cout<<s.maximalSquare(matrix)<<endl;
	return 0;
}


