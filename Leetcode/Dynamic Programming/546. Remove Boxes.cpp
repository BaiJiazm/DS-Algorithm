/*
	���������𣿲�˼��Ϊʲô��Զ������Ŀ�ѡ��Ҿ��ô�����ѵ��У�
	1.��������������״̬������ͬ����ǰ�����ി������ҪO(n!)��Ŀ��������·һ����ά���飬 ��ͷ��β���й�λ��˳�򣬶�ά�����±������Ч�����Ӧ״̬��������Ŀ�������в�ͨ�ġ�
	����������ά״̬���ǿ϶����ܼ�¼����״ֵ̬��
	2.�����Ч���ô���ʵ�֡���ǰ�������е�DP���ⶼ�Ƿǵݹ鰴�����и��¡����Ǵ���ȴҪ�õݹ�д����ѡ�����Ч�������ģ��С��ͬʱ��¼��Ӧ�Ѿ�������״̬�� 
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
