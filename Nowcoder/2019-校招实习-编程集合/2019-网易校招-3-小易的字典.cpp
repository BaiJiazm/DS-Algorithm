/*
���ӣ�https://www.nowcoder.com/questionTerminal/12b1b8ef17e1441f86f322b250bff4c0

������ϣ�n��'a'��m��'z'��ֻ�����$C_{n+m}^n$����Ϊcount(n+m,n) �����ʡ�
˼·��
�����һ���ַ�Ϊa����ʣ��n-1��'a'��m��'z'��ɵ�������ֻ�ܹ���count(n-1+m,n-1)�����ʣ������ֵ���ǰcount(n-1+m,n-1)�����ʡ�
�Ƚ�k��count(n-1+m,n-1)����kС��˵��k��ǰcount(n-1+m,n-1)�����ʣ����һ���ַ���Ϊ'a'�������⻯Ϊ��������(n-1��'a'��m��'z')�ҵ���k������
��k����˵����һ���ַ���Ϊ'z',��������'z'��ͷ�ĵ����еĵ�k-count(n-1+m,n-1)���������⻯Ϊ��������(n��'a'��m-1��'z')�ҵ���k-count(n+m-1,m-1)�����ʡ�
eg:n=2,m=2,k=5
�����һ���ַ�Ϊa,��ʣ��1��a,2��zֻ�ܹ���3�����ʣ������ֵ���ǰ3������(aamm,amam,amma)
k>3�����һ���ַ���Ϊz��ԭ���⻯Ϊ��n=2,m=1,k=2������ʣ��2��a��1��z���ҵ���2������

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		void solve(int n, int m, long long k) {
			vector<char> x;//
			while (n && m) {
				//ÿ�ε��������ģ����һ����λ
				////�������:���赱ǰ�������ַ�Ϊa��ʣ��n-1��a����ʣ��n - 1 +m ��λ�ù��еĿ�����
				long long count = 1;
				for (int i = 0; i < n - 1; i++) {//�������
					count *= n - 1 + m - i;
					count /= (i + 1);
					if (count > k)
						break;//��ֹԽ�硣count>k�Ϳ����˳�������
				}
				if (k <= count) {//���kС�ڵ���count����������ַ���ȷӦΪa
					x.push_back('a');
					n--;//��������Ϊ n-1��a��m��z ���ҵ�k��
				} else {
					x.push_back('z');
					m--;//��������Ϊ n-1��a��m��z ���ҵ�k-count��
					k -= count;
				}
			}
			//ѭ��������ʣ��������ֻ����"aa..aaa" �� "zz..zzz"1�����
			if (k != 1) {//
				cout << -1;
				return;
			}
			while (n--)
				x.push_back('a');
			while (m--)
				x.push_back('z');
			for (int i = 0; i < x.size(); i++) {
				cout << x[i];
			}
		}
};

int main() {
	Solution a;
	int n, m;
	long long k;
	while (cin >> n >> m >> k) {
		a.solve(n, m, k);
	}
	return 0;
}
