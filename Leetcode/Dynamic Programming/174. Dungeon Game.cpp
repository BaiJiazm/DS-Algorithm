#include "headFile"

//非常不错的题目，这种自己做出来就是标答的感觉真好!
class Solution {
	public:
		int calculateMinimumHP(vector<vector<int>>& dungeon) {
			int row=dungeon.size();
			int col=dungeon[0].size();
			vector<vector<int>>dp(row,vector<int>(col));
			--row;
			--col;
			dp[row][col]=max(1,1-dungeon[row][col]);

			for (int i=col-1; i>=0; --i) {
				dp[row][i]=max(1,dp[row][i+1]-dungeon[row][i]);
			}
			for (int i=row-1; i>=0; --i) {
				dp[i][col]=max(1,dp[i+1][col]-dungeon[i][col]);
			}
			for (int i=row-1; i>=0; --i)
				for (int j=col-1; j>=0; --j) {
					dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
				}

			return dp[0][0];
		}
};

int main() {
	vector<int>d1({-3});
	vector<int>d2({-7});
	vector<vector<int>> dungeon;
	dungeon.push_back(d1);
	dungeon.push_back(d2);
	Solution s;
	cout<<s.calculateMinimumHP(dungeon)<<endl;

}
