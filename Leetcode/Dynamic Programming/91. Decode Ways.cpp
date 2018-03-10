class Solution {
	public:
		int numDecodings(string s) {
			if (s.length() == 0) return 0;
			// 初始化f数组
			vector<int> f(s.length() + 1);
			f[0] = 1;
			// 从1~n依次计算f[i]
			for (int i = 1; i <= s.length(); i++) {
				// 枚举最后一个字母匹配的位数
				if (s[i - 1] > '0') {
					f[i] += f[i - 1];
				}
				if (i > 1 && s.substr(i - 2, 2) >= "10" && s.substr(i - 2, 2) <= "26") {
					f[i] += f[i - 2];
				}
			}
			// 返回答案
			return f[s.length()];
		}
};
