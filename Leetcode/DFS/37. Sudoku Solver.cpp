/*
	技巧一：善于使用/ %运算将二维参数一维化，可以节省空间，减少判断，缩减代码；
	技巧二：一般凭最简单的第一思维想出来的算法都是没有什么优点的，大家都是这样想的要不断升华，反面、整体思考，搜索类的题目最重要的是优化！ 
*/
class Solution {
	public:
		void solveSudoku(vector<vector<char>>& board) {
			memset(row,0,sizeof(row));
			memset(col,0,sizeof(col));
			memset(sqr,0,sizeof(sqr));
			for (int i=0; i<9; ++i)
				for (int j=0; j<9; ++j)
					if (board[i][j]!='.') {
						int c=board[i][j]-'0';
						row[i][c]=col[j][c]=sqr[i/3*3+j/3][c]=1;
					}
			dfs(board,0);
			return ;
		}
		int row[10][10];
		int col[10][10];
		int sqr[10][10];
		bool dfs(vector<vector<char>>&board,int pos) {
			if (pos==81)
				return true;
			int x=pos/9,y=pos%9;
			if (board[x][y]!='.')
				return dfs(board,pos+1);
			for (int i=1; i<=9; ++i) {
				if (row[x][i]||col[y][i]||sqr[x/3*3+y/3][i])
					continue;
				row[x][i]=col[y][i]=sqr[x/3*3+y/3][i]=1;
				board[x][y]='0'+i;
				if (dfs(board,pos+1))
					return true;
				row[x][i]=col[y][i]=sqr[x/3*3+y/3][i]=0;
			}
			board[x][y]='.';
			return false;
		}
};
