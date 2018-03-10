class Solution {
	public:
		int numDecodings(string s) {
			if (s.length() == 0) return 0;
			// ��ʼ��f����
			vector<int> f(s.length() + 1);
			f[0] = 1;
			// ��1~n���μ���f[i]
			for (int i = 1; i <= s.length(); i++) {
				// ö�����һ����ĸƥ���λ��
				if (s[i - 1] > '0') {
					f[i] += f[i - 1];
				}
				if (i > 1 && s.substr(i - 2, 2) >= "10" && s.substr(i - 2, 2) <= "26") {
					f[i] += f[i - 2];
				}
			}
			// ���ش�
			return f[s.length()];
		}
};
