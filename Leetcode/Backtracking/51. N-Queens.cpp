//未优化版本的回溯，纯暴力
class Solution {
	public:
		std::vector<std::vector<std::string> > solveNQueens(int n) {
			std::vector<std::vector<std::string> > res;
			std::vector<std::string> nQueens(n, std::string(n, '.'));
			solveNQueens(res, nQueens, 0, n);
			return res;
		}
	private:
		void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
			if (row == n) {
				res.push_back(nQueens);
				return;
			}
			for (int col = 0; col != n; ++col)
				if (isValid(nQueens, row, col, n)) {
					nQueens[row][col] = 'Q';
					solveNQueens(res, nQueens, row + 1, n);
					nQueens[row][col] = '.';
				}
		}
		bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
			//check if the column had a queen before.
			for (int i = 0; i != row; ++i)
				if (nQueens[i][col] == 'Q')
					return false;
			//check if the 45° diagonal had a queen before.
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
				if (nQueens[i][j] == 'Q')
					return false;
			//check if the 135° diagonal had a queen before.
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
				if (nQueens[i][j] == 'Q')
					return false;
			return true;
		}
};

//可以用bit进行col的有效位置记录，缩短时间，但是用一维数组效果是一样的，此处不是重点
//bit用法在多处需要判断并且需要多次传递时可节省空间和时间，只用一次时不明显

class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<string>>ans;
			vector<string>oneSolve(n,string(n,'.'));
			solve(ans,oneSolve,n,0,0);
			return ans;
		}
		void solve(vector<vector<string>>&ans,vector<string>&oneSolve,const int &row,int n,int used) {
			if (row==n) {
				ans.push_back(oneSolve);
				return ;
			}
			for (int i=0; i<row; ++i)
				if (isValid(oneSolve,n,i,used,row)) {
					oneSolve[n][i]='Q';
					used|=(1<<i);
					solve(ans,oneSolve,row,n+1,used);
					oneSolve[n][i]='.';
					used^=(1<<i);
				}
			return ;
		}
		bool isValid(vector<string>&oneSolve,int n,int i,int &used,const int &row) {
			if (used&1<<i)
				return false;
			int r,c;
			for (r=n-1,c=i-1; r>=0&&c>=0; --r,--c)
				if (oneSolve[r][c]=='Q')
					return false;
			for (r=n-1,c=i+1; r>=0&&c<row; --r,++c)
				if (oneSolve[r][c]=='Q')
					return false;
			return true;
		}
};

/*
	优化版本，运用数学方法映射，将行、列、45度、135度方向在O(1)的时间进行选择！
	https://leetcode.com/problems/n-queens/#/solutions
Solution B: Use flag vectors as bitmask, 4ms:

The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 2 * n - 1. When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal No. is n - 1 + col - row. We can use three arrays to indicate if the column or the diagonal had a queen before, if not, we can put a queen in this position and continue.

NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.

*/
/**    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  */

class Solution {
	public:
		std::vector<std::vector<std::string> > solveNQueens(int n) {
			std::vector<std::vector<std::string> > res;
			std::vector<std::string> nQueens(n, std::string(n, '.'));
			std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
			solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
			return res;
		}
	private:
		void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
			if (row == n) {
				res.push_back(nQueens);
				return;
			}
			for (int col = 0; col != n; ++col)
				if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
					flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
					nQueens[row][col] = 'Q';
					solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
					nQueens[row][col] = '.';
					flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
				}
		}
};


//进一步写法优化，三个数组和为一个空间
/*
But we actually do not need to use three arrays, we just need one. Now, when reach [row, col], the subscript of column is col, the subscript of 45° diagonal is n + row + col and the subscript of 135° diagonal is n + 2 * n - 1 + n - 1 + col - row.
*/
class Solution {
	public:
		std::vector<std::vector<std::string> > solveNQueens(int n) {
			std::vector<std::vector<std::string> > res;
			std::vector<std::string> nQueens(n, std::string(n, '.'));
			/*
			flag[0] to flag[n - 1] to indicate if the column had a queen before.
			flag[n] to flag[3 * n - 2] to indicate if the 45° diagonal had a queen before.
			flag[3 * n - 1] to flag[5 * n - 3] to indicate if the 135° diagonal had a queen before.
			*/
			std::vector<int> flag(5 * n - 2, 1);
			solveNQueens(res, nQueens, flag, 0, n);
			return res;
		}
	private:
		void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag, int row, int &n) {
			if (row == n) {
				res.push_back(nQueens);
				return;
			}
			for (int col = 0; col != n; ++col)
				if (flag[col] && flag[n + row + col] && flag[4 * n - 2 + col - row]) {
					flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 0;
					nQueens[row][col] = 'Q';
					solveNQueens(res, nQueens, flag, row + 1, n);
					nQueens[row][col] = '.';
					flag[col] = flag[n + row + col] = flag[4 * n - 2 + col - row] = 1;
				}
		}
};
