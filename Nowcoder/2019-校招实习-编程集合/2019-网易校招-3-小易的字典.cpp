/*
链接：https://www.nowcoder.com/questionTerminal/12b1b8ef17e1441f86f322b250bff4c0

排列组合，n个'a'和m个'z'，只能组成$C_{n+m}^n$，记为count(n+m,n) 个单词。
思路：
假设第一个字符为a，则剩下n-1个'a'和m个'z'组成的子序列只能构成count(n-1+m,n-1)个单词，且是字典中前count(n-1+m,n-1)个单词。
比较k和count(n-1+m,n-1)，若k小，说明k是前count(n-1+m,n-1)个单词，则第一个字符必为'a'。子问题化为在子序列(n-1个'a'和m个'z')找到第k个单词
若k大，则说明第一个字符必为'z',单词是以'z'开头的单词中的第k-count(n-1+m,n-1)个。子问题化为在子序列(n个'a'和m-1个'z')找到第k-count(n+m-1,m-1)个单词。
eg:n=2,m=2,k=5
假设第一个字符为a,则剩下1个a,2个z只能构成3个单词，且是字典中前3个单词(aamm,amam,amma)
k>3，则第一个字符必为z。原问题化为在n=2,m=1,k=2，即在剩下2个a，1个z中找到第2个单词

*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
	public:
		void solve(int n, int m, long long k) {
			vector<char> x;//
			while (n && m) {
				//每次迭代问题规模缩减一个单位
				////排列组合:假设当前序列首字符为a，剩下n-1个a放在剩下n - 1 +m 个位置共有的可能数
				long long count = 1;
				for (int i = 0; i < n - 1; i++) {//求组合数
					count *= n - 1 + m - i;
					count /= (i + 1);
					if (count > k)
						break;//防止越界。count>k就可以退出计算了
				}
				if (k <= count) {//如果k小于等于count，则表明首字符的确应为a
					x.push_back('a');
					n--;//问题缩减为 n-1个a和m个z 中找第k大
				} else {
					x.push_back('z');
					m--;//问题缩减为 n-1个a和m个z 中找第k-count大
					k -= count;
				}
			}
			//循环结束后，剩余子序列只存在"aa..aaa" 或 "zz..zzz"1种情况
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
