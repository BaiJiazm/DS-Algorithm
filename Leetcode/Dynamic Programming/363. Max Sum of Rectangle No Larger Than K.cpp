#include "headFile"

/*
思路: 一种naive的算法就是枚举每个矩形块, 时间复杂度为O((mn)^2),
可以做少许优化时间复杂度可以降低到O(mnnlogm), 其中m为行数, n为列数.

先求出任意两列之间的所有数的和, 然后再枚举任意两行之间的和, 而我们优化的地方就在后者.
我们用s[x]来表示第x行从a列到b列的和. 遍历一遍从第0行到最后一行的求和数组,
并依次将其放到二叉搜索树中,这样当我们知道了从第0行到当前行的和的值之后,
我们就可以用lower_bound在O(log n)的时间复杂度内找到能够使得从之前某行到当前行的矩阵值最接近k.
也就是说求在之前的求和数组中找到第一个位置使得大于(curSum - k), 这种做法的原理是在curSum之下规定了一个bottom-line,
在这上面的第一个和就是(curSum-val)差值与k最接近的数. 还需要注意的是预先为二叉搜索树加一个0值,
这种做法的原理是如果当前curSum小于k, 那么至少本身是一个潜在的解.
*/

//解法一：暴力，但不是完全纯暴力，利用DP快速求和  算法复杂度O（n^2*m^2）    Time:789ms
class Solution {
	public:
		int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
			if (matrix.empty() || matrix[0].empty()) return 0;
			int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
			int sum[m][n];
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					int t = matrix[i][j];
					if (i > 0) t += sum[i - 1][j];
					if (j > 0) t += sum[i][j - 1];
					if (i > 0 && j > 0) t -= sum[i - 1][j - 1];
					sum[i][j] = t;
					for (int r = 0; r <= i; ++r) {
						for (int c = 0; c <= j; ++c) {
							int d = sum[i][j];
							if (r > 0) d -= sum[r - 1][j];
							if (c > 0) d -= sum[i][c - 1];
							if (r > 0 && c > 0) d += sum[r - 1][c - 1];
							if (d <= k) res = max(res, d);
						}
					}
				}
			}
			return res;
		}
};

//算法复杂度O（m*m*n*logn）    Time:149ms
class Solution {
	public:
		int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
			if (matrix.empty() || matrix[0].empty()) return 0;
			int m = matrix.size(), n = matrix[0].size(), res = INT_MIN;
			for (int i = 0; i < n; ++i) {
				vector<int> sum(m, 0);
				for (int j = i; j < n; ++j) {
					for (int k = 0; k < m; ++k) {
						sum[k] += matrix[k][j];
					}
					int curSum = 0, curMax = INT_MIN;
					set<int> s;
					s.insert(0);
					for (auto a : sum) {
						curSum += a;
						auto it = s.lower_bound(curSum - k);
						if (it != s.end()) curMax = max(curMax, curSum - *it);
						s.insert(curSum);
					}
					res = max(res, curMax);
				}
			}
			return res;
		}
};


/*
	总结：	对于求连续区域问题都可以采用DP区域减法，快速求出目标。
			一维:后者-前者
			二维:区域减法
			...对于更多维也一样
*/
