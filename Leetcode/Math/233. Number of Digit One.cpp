//����ѧ���⣬��������ѧ�Ƶ��⼰�ҹ�����Ŀ˼ά��Ҫ��ǿ�����Ƕ�����·��
//�������ӣ�ѧϰ�Ƶ� 
//https://leetcode.com/problems/number-of-digit-one/solution/

class Solution {
	public:
		int countDigitOne(int n) {
			int countr = 0;
			for (long long i = 1; i <= n; i *= 10) {
				long long divider = i * 10;
				countr += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
			}
			return countr;
		}
};
