/*
	��Ŀ���壺һ����������Ķ�ά�����ҵ���kСԪ��ֵ��
	������һ��˼�룬�кܶ��Ӧ�ó�����ʹ�÷�ʽ������Ŀ��һ�ַ�ʽ��
	Ŀ��ֵ�����Ͻ�Ԫ�غ����½�Ԫ��֮�䣬��Χ��С��һ���ģ���Ȼÿ��Сһ�η�Χ����O(n*logn)���㷨ʱ�临�Ӷ�ΪO(n*logn*logX)
	�㷨��ʱ�临�Ӷ���Ȼ�ȼۺá�
	�״������left=mid+1;right=mid;
	����һ�������������˼����������left��right����ָ�򡣷��������һ�㿼��left==mid�Լ�left=mid-1���ɡ�
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


//����ÿ��������㷨�����Ż��� O(nlogX)
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
