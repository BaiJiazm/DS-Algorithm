/*

�ܵ���˵�������Ŀ���ǲ�����ʵ���շ������ǱȽϼ򵥵ġ�
һ����������100�� ���Ӷ�һ��ΪO(n^3)����Ȼ�Ƕ�ά����+֮��ı�����
�����Ŀ�Ĵ��˼·����֪���ģ����������ֻͨ����101/211��case��

��̬�滮����������һ���ؼ������ڣ�
1.���������Ƿ���������еĿ����ԣ�ÿһ�ε�������ֵ�Ĺ��̴�����������ʵ�ʹ��̡�
2.�������������̶̳ȣ�������Ҫ��һ��ķ����Ƕ����Ŀ������򵥵�һЩ���ӷ������֣���������ƹ㡣

����˼·��
    i     k   j
	~ a ~ a ~ a
	���������������dp[i][j]��ʾ�������ⲿ����s[i]-s[j]��ӡ��Ҫ�����ٲ�����
	i<=k<j	��s[k]==s[j], ��ôdp[i][j]��һ������ֵΪdp[i][k]+dp[k+1][j-1]��j����aͬk����aһ�𻭳���

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
