//我的行列二分解法，还行，不过还是太笨了点 
class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if(matrix.size()==0||matrix[0].size()==0)
				return false;
			int r1=0,r2=matrix.size()-1;
			int c1=0,c2=matrix[0].size()-1;
			int m,l,r;
			while(c1<=c2&&r1<=r2) {
				l=r1,r=r2;
				while(l<=r) {
					m=(l+r)>>1;
					if(matrix[m][c2]==target)
						return true;
					else if(matrix[m][c2]<target)
						l=m+1;
					else
						r=m-1;
				}
				r1=l;
				if(c1>c2||r1>r2)
					return false;
				--c2;

				l=c1,r=c2;
				while(l<=r) {
					m=(l+r)>>1;
					if(matrix[r2][m]==target)
						return true;
					else if(matrix[r2][m]<target)
						l=m+1;
					else
						r=m-1;
				}
				--r2;
				c1=l;
			}
			return false;
		}
};

//discuss区的牛逼解法，O（m+n）复杂度，而且代码实现简单。 
class Solution {
	public:
		bool searchMatrix(vector<vector<int>>& matrix, int target) {
			int m = matrix.size();
			if (m == 0) return false;
			int n = matrix[0].size();

			int i = 0, j = n - 1;
			while (i < m && j >= 0) {
				if (matrix[i][j] == target)
					return true;
				else if (matrix[i][j] > target) {
					j--;
				} else
					i++;
			}
			return false;
		}
};
