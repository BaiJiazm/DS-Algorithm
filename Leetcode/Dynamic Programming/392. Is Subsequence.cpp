#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<numeric>
using namespace std;

//解法一：很浪费时间空间
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int slen = s.length();
		int tlen = t.length();
		if (slen > tlen)
			return false;
		vector<vector<bool>>dp(slen + 1, vector<bool>(tlen + 1, false));
		int i, j;
		for (i = 0; i <= tlen; ++i)
			dp[0][i] = true;
		for (i = 1; i <= slen; ++i)
			for (j = i; j <= tlen; ++j)
				dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] && s[i - 1] == t[j - 1];
		return dp[slen][tlen];
	}
};

//解法二：贪心寻找
class Solution {
public:
	bool isSubsequence(string s, string t) {
		int slen = s.length();
		int tlen = t.length();
		int i, j;
		for (i = 0, j = 0; i < slen; ++i, ++j) {
			while (j < tlen&&s[i] != t[j])
				++j;
			if (j >= tlen)
				return false;
		}
		return true;
	}
};

int main()
{
	string s = "abc";
	string t = "ahbgdc";
	Solution sl;
	cout << sl.isSubsequence(s, t);
	system("pause");
	return 0;
}