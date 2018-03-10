class Solution {
	public:
		void contaminate(vector<vector<char> > &grid, int i, int j) {
			if(i>0&&grid[i-1][j]=='1') {
				grid[i-1][j]='0';
				contaminate(grid, i-1, j);
			}
			if(j>0&&grid[i][j-1]=='1') {
				grid[i][j-1]='0';
				contaminate(grid, i, j-1);
			}
			if(i<grid.size()-1&&grid[i+1][j]=='1') {
				grid[i+1][j]='0';
				contaminate(grid, i+1, j);
			}
			if(j<grid[0].size()-1&&grid[i][j+1]=='1') {
				grid[i][j+1]='0';
				contaminate(grid, i, j+1);
			}
		}
		int numIslands(vector<vector<char>> &grid) {
			int n=grid.size();
			if(n==0) return 0;
			int m=grid[0].size();

			int cnt=0;
			for(int i=0; i<n; i++) {
				for(int j=0; j<m; j++) {
					if(grid[i][j]=='1') {
						cnt++;
						contaminate(grid, i, j);
					}
				}
			}
			return cnt;
		}
};
