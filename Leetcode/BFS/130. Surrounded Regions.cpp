/*
X X O X  ->       X X O X    ->       X X X X
X X X X           X X X X             X X X X
X O X X           X 1 X X             X O X X
X O X X           X 1 X X             X O X X
*/

class Solution {
	public:
		void solve(vector<vector<char>>& board) {
			int i,j;
			int row=board.size();
			if(!row)
				return;
			int col=board[0].size();

			for(i=0; i<row; i++) {
				check(board,i,0,row,col);
				if(col>1)
					check(board,i,col-1,row,col);
			}
			for(j=1; j+1<col; j++) {
				check(board,0,j,row,col);
				if(row>1)
					check(board,row-1,j,row,col);
			}
			for(i=0; i<row; i++)
				for(j=0; j<col; j++)
					if(board[i][j]=='O')
						board[i][j]='X';
			for(i=0; i<row; i++)
				for(j=0; j<col; j++)
					if(board[i][j]=='1')
						board[i][j]='O';
		}
		void check(vector<vector<char> >&vec,int i,int j,int row,int col) {
			if(vec[i][j]=='O') {
				vec[i][j]='1';
				if(i>1)
					check(vec,i-1,j,row,col);
				if(j>1)
					check(vec,i,j-1,row,col);
				if(i+1<row)
					check(vec,i+1,j,row,col);
				if(j+1<col)
					check(vec,i,j+1,row,col);
			}
		}
};
