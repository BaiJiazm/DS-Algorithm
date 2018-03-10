/*
	这道题很难吗？不思考为什么永远觉得题目难。我觉得此题的难点有：
	1.摸索清楚子问题和状态量。不同于以前大多此类纯暴力需要O(n!)题目，基本套路一个二维数组， 从头到尾，有关位置顺序，二维数组下标可以有效存放相应状态量。此题目这样是行不通的。
	仅仅依赖二维状态量是肯定不能记录完整状态值。
	2.如何有效的用代码实现。以前几乎所有的DP问题都是非递归按照行列更新。但是此题却要用递归写法最佳。能有效将问题规模变小，同时记录相应已经求解过的状态。 
*/ 
class Solution {
	private:
		const int maxn = 105;
		int d[maxn][maxn][maxn];
		int c[maxn], len[maxn];
	public:
		int dfs(int i, int j, int k) {
			if (d[i][j][k] != -1) return d[i][j][k];
			if (i > j) return 0;
			d[i][j][k] = dfs(i, j - 1, 0) + (len[j] + k) * (len[j] + k);
			for (int pos = i; pos < j; pos++) {
				if (c[pos] == c[j]) d[i][j][k] = max(d[i][j][k], dfs(i, pos, len[j] + k) + dfs(pos + 1, j - 1, 0));
			}
			return d[i][j][k];
		}

		int removeBoxes(vector<int>& boxes) {
			int n = 0;
			memset(c, 0, sizeof(c));
			memset(len, 0, sizeof(len));
			memset(d, -1, sizeof(d));
			for (int i = 0; i < boxes.size(); i++) {
				if (i == 0 || boxes[i] != boxes[i - 1]) c[++n] = boxes[i], len[n] = 1;
				else len[n]++;
			}
			return dfs(1, n, 0);
		}
};
