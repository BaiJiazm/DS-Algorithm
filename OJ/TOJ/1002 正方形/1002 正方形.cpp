#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
	public:
		int maximalSquare(vector<vector<char> >& matrix) {
			int maxSquare=0;
			if (matrix.size()==0||matrix[0].size()==0)
				return 0;
			int row=matrix.size(),col=matrix[0].size();

			vector<vector<int> >dp(row+1,vector<int>(col+1,0));
			for (int i=0; i<row; ++i) {
				for (int j=0; j<col; ++j) {
					if (matrix[i][j]-'0') {
						dp[i+1][j+1]=min(dp[i][j],min(dp[i+1][j],dp[i][j+1]))+1;
					} else
						dp[i+1][j+1]=0;
					maxSquare=max(maxSquare,dp[i+1][j+1]);
				}
			}
			return  maxSquare;
		}
};

int main() {
	vector<vector<char> > matrix;
	int m,n;
	int i,j;
	while(cin>>n>>m) {
		matrix.resize(n,vector<char>(m));
		for (i=0; i<n; ++i)
			for (j=0; j<m; ++j)
				cin>>matrix[i][j];

		Solution s;
		cout<<s.maximalSquare(matrix)<<endl;
	}
	return 0;
}


