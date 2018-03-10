/*
	����һ������ʹ��/ %���㽫��ά����һά�������Խ�ʡ�ռ䣬�����жϣ��������룻
	���ɶ���һ��ƾ��򵥵ĵ�һ˼ά��������㷨����û��ʲô�ŵ�ģ���Ҷ����������Ҫ�������������桢����˼�������������Ŀ����Ҫ�����Ż��� 
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
