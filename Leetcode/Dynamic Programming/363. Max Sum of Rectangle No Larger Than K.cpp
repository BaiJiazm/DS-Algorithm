#include "headFile"

/*
˼·: һ��naive���㷨����ö��ÿ�����ο�, ʱ�临�Ӷ�ΪO((mn)^2),
�����������Ż�ʱ�临�Ӷȿ��Խ��͵�O(mnnlogm), ����mΪ����, nΪ����.

�������������֮����������ĺ�, Ȼ����ö����������֮��ĺ�, �������Ż��ĵط����ں���.
������s[x]����ʾ��x�д�a�е�b�еĺ�. ����һ��ӵ�0�е����һ�е��������,
�����ν���ŵ�������������,����������֪���˴ӵ�0�е���ǰ�еĺ͵�ֵ֮��,
���ǾͿ�����lower_bound��O(log n)��ʱ�临�Ӷ����ҵ��ܹ�ʹ�ô�֮ǰĳ�е���ǰ�еľ���ֵ��ӽ�k.
Ҳ����˵����֮ǰ������������ҵ���һ��λ��ʹ�ô���(curSum - k), ����������ԭ������curSum֮�¹涨��һ��bottom-line,
��������ĵ�һ���;���(curSum-val)��ֵ��k��ӽ�����. ����Ҫע�����Ԥ��Ϊ������������һ��0ֵ,
����������ԭ���������ǰcurSumС��k, ��ô���ٱ�����һ��Ǳ�ڵĽ�.
*/

//�ⷨһ����������������ȫ������������DP�������  �㷨���Ӷ�O��n^2*m^2��    Time:789ms
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

//�㷨���Ӷ�O��m*m*n*logn��    Time:149ms
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
	�ܽ᣺	�����������������ⶼ���Բ���DP����������������Ŀ�ꡣ
			һά:����-ǰ��
			��ά:�������
			...���ڸ���άҲһ��
*/
