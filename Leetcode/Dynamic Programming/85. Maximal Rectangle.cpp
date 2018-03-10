#include "headFile"

class Solution {
	public:
		int maximalRectangle(vector<vector<char>>& matrix) {
			int row=matrix.size();
			if (!row)
				return 0;
			int col=matrix[0].size();
			if (!col)
				return 0;
			vector<vector<int>>dp(row+1,vector<int>(col+1,0));
			for (int j=1; j<=col; ++j)
				for (int i=1; i<=row; ++i)
					if (matrix[i-1][j-1]=='1')
						dp[i][j]=dp[i-1][j]+1;
			int ans=0;
			for (auto a:dp)
				ans=max(ans,maxi(a));
			return ans;
		}
	private:
		int maxi(const vector<int>&v) {
			int size=v.size();
			int ans=0;
			for (int i=1; i<size; ++i) {
				int minh=v[i];
				for (int j=i; j<size&&v[j]; ++j) {
					minh=min(minh,v[j]);
					ans=max(ans,(j-i+1)*minh);
				}
			}
			return ans;
		}
};

int main() {
	freopen("test.txt","r",stdin);

	vector<vector<char>> matrix(4,vector<char>(5));
	for (int i=0; i<4; ++i)
		for (int j=0; j<5; ++j)
			cin>>matrix[i][j];
	Solution s;
	cout<<s.maximalRectangle(matrix)<<endl;
	return 0;
}

