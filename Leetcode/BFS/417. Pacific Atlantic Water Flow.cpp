/*	解法一：DFS     精彩部分：用bit位表示访问情况
    time:52ms
*/
class Solution {
	public:
		vector<pair<int, int>> res;
		vector<vector<int>> visited;
		void dfs(vector<vector<int>>& matrix, int x, int y, int pre, int preval) {
			if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
			        || matrix[x][y] < pre || (visited[x][y] & preval) == preval)
				return;
			visited[x][y] |= preval;
			if (visited[x][y] == 3) res.push_back({x, y});
			dfs(matrix, x + 1, y, matrix[x][y], visited[x][y]);
			dfs(matrix, x - 1, y, matrix[x][y], visited[x][y]);
			dfs(matrix, x, y + 1, matrix[x][y], visited[x][y]);
			dfs(matrix, x, y - 1, matrix[x][y], visited[x][y]);
		}

		vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
			if (matrix.empty()) return res;
			int m = matrix.size(), n = matrix[0].size();
			visited.resize(m, vector<int>(n, 0));
			for (int i = 0; i < m; i++) {
				dfs(matrix, i, 0, INT_MIN, 1);
				dfs(matrix, i, n - 1, INT_MIN, 2);
			}
			for (int i = 0; i < n; i++) {
				dfs(matrix, 0, i, INT_MIN, 1);
				dfs(matrix, m - 1, i, INT_MIN, 2);
			}
			return res;
		}
};

/*	解法二：BFS     为什么比DFS还慢？
    time:62ms
*/
class Solution {
	public:
		vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
			if (matrix.empty()) return res;
			int m = matrix.size(), n = matrix[0].size();
			visited.resize(m, vector<int>(n, 0));
			queue< pair<int,int> >q;
			for (int i=0; i<m; ++i) {
				visited[i][0]=1;
				q.push({i,0});
			}
			for (int i=1; i<n; ++i) {
				visited[0][i]=1;
				q.push({0,i});
			}
			BFS(matrix,q,1);
			for (int i=0; i<n; ++i) {
				visited[m-1][i]|=2;
				q.push({m-1,i});
			}
			for (int i=0; i<m; ++i) {
				visited[i][n-1]|=2;
				q.push({i,n-1});
			}
			BFS(matrix,q,2);
			for (int i=0;i<m;++i)
				for (int j=0;j<n;++j)
					if (visited[i][j]==3)
						res.push_back({i,j});
			return res;
		}
	private:
		vector< vector<int> >visited;
		vector<pair<int, int>> res;
		void BFS(vector<vector<int>>& matrix,queue< pair<int,int> > &q,int mark) {
			int m = matrix.size(), n = matrix[0].size();
			while(!q.empty()) {
				int x=q.front().first,y=q.front().second;
				int depth=matrix[x][y];
				q.pop();

				if (x-1 >= 0 && (visited[x-1][y] & mark) != mark&&matrix[x-1][y] >= depth ) {
					visited[x-1][y]|=mark;
					q.push({x-1,y});
				}
				if (x+1 < m&& (visited[x+1][y] & mark) != mark&&matrix[x+1][y] >= depth ) {
					visited[x+1][y]|=mark;
					q.push({x+1,y});
				}
				if (y-1 >= 0&& (visited[x][y-1] & mark) != mark&&matrix[x][y-1] >= depth ) {
					visited[x][y-1]|=mark;
					q.push({x,y-1});
				}
				if (y+1 < n&& (visited[x][y+1] & mark) != mark&&matrix[x][y+1] >= depth ) {
					visited[x][y+1]|=mark;
					q.push({x,y+1});
				}
			}
			return ;
		}
};

