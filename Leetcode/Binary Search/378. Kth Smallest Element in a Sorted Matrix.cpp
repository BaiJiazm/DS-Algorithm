/*
	题目大义：一个行列有序的二维矩阵，找到第k小元素值。
	二分是一种思想，有很多的应用场景和使用方式。本题目是一种方式。
	目标值在左上角元素和右下角元素之间，范围大小是一定的，虽然每缩小一次范围均需O(n*logn)，算法时间复杂度为O(n*logn*logX)
	算法的时间复杂度仍然比价好。
	易错点在于left=mid+1;right=mid;
	对于一般二分搜索均需思考最后情况和left，right最终指向。分析的情况一般考虑left==mid以及left=mid-1即可。
*/
class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			int n = matrix.size();
			int le = matrix[0][0], ri = matrix[n - 1][n - 1];
			int mid = 0;
			while (le < ri) {
				mid = le + (ri-le)/2;
				int num = 0;
				for (int i = 0; i < n; i++) {
					int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
					num += pos;
				}
				if (num < k) {
					le = mid + 1;
				} else {
					ri = mid;
				}
			}
			return le;
		}
};


//利用每列有序对算法进行优化， O(nlogX)
class Solution {
	public:
		int kthSmallest(vector<vector<int>>& matrix, int k) {
			int left = matrix[0][0], right = matrix.back().back();
			while (left < right) {
				int mid = left + (right - left) /2, cnt = 0;
				cnt += search_less_equal(matrix, mid);
				if (cnt < k) left = mid + 1;
				else right = mid;
			}
			return left;
		}
	private:
		int search_less_equal(vector<vector<int>>& matrix, int target) {
			int n = matrix.size(), i = n - 1, j = 0, res = 0;
			while (i >= 0 && j < n) {
				if (matrix[i][j] <= target) {
					res += i + 1;
					j++;
				} else {
					i--;
				}
			}
			return res;
		}
};
