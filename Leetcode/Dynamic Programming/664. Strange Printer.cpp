/*

总的来说，这道题目还是不错，其实掌握方法后还是比较简单的。
一看数据量，100， 复杂度一般为O(n^3)，必然是二维数组+之间的遍历。
这道题目的大概思路还是知道的，但是最后还是只通过了101/211个case。

动态规划解此类问题的一个关键点在于：
1.求解过程中是否包含了所有的可能性，每一次的求最优值的过程代表着怎样的实际过程。
2.题意规则理解的深刻程度，这点很重要，一般的分析是多读题目，从最简单的一些例子分析入手，向复杂情况推广。

本题思路：
    i     k   j
	~ a ~ a ~ a
	考虑上述的情况，dp[i][j]表示不考虑外部，仅s[i]-s[j]打印需要的最少步数。
	i<=k<j	若s[k]==s[j], 那么dp[i][j]的一个可能值为dp[i][k]+dp[k+1][j-1]（j处的a同k处的a一起画出）

*/
#include<iostream>
#include<string>
using namespace std;

class Solution {
	public:
		int strangePrinter(string s) {
			if(s.empty())
				return 0;
			#define MAXLEN 105
			int dp[MAXLEN][MAXLEN]= {0};
			int len=s.length();
			int i,j,k;
			for(j=0; j<len; ++j) {
				dp[j][j]=1;
				for(i=j-1; i>=0; --i) {
					int mi=dp[i][j-1]+1;
					for(k=j-1; k>=i; --k)
						if(s[k]==s[j])
							mi=min(mi, dp[i][k]+dp[k+1][j-1]);
					dp[i][j]=mi;
				}
			}
			return dp[0][len-1];
		}
};

int main() {
	freopen("test.txt", "r", stdin);

	string  test1;
	Solution s;
	while(getline(cin, test1)) {
		cout<<s.strangePrinter(test1)<<endl;
	}
	return 0;
}
