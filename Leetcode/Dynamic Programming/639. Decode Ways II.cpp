/*
	��Ŀ���壺��һ�����ֺ�'*'��ɵ��ַ������е���ĸ�����룬�����뷽������
	��Ŀ����Ƚϼ򵥣�һ������Ŀ�ṹӦ�ú�����֪��Ӧ������DP����������һֱ�������ac��˼����ϸ�ڷ���û�д���
	��������ʱ�����ŷ�������������ˡ����ǻ���C++û�й�ȫ����
	ǰ������һ����Ŀ����Ϊÿ�ζ����������Χlong long []���飬��ȷ����Memory Limit Error��������ζ�̬���룬������int����Ȼ���ǵ������ݿ��������
	���������ʱlong long�������棬��Ϊint*int��ֵΪlong long�����ԣ���ʵint*int=int��������ܣ�����long longתΪlong long�����Դ���
	���������˿�����������������ڳ��������L�����ǻ��ǲ��ԣ���Ϊgcc��linux��������sizeof(long)=4,sizeof(long long)=8������ΪLL��
	
	�����ܽ᣺������������Ĵ���̫�����ҳ����м��ζ�����ͬ�����󣬻��ǲ������ԣ�һ��Ҫ�������ġ�
		�Ҵ�������Ҫ������ϸ�������߼�˼����
			����Ŀ�д�����ʾ�����Թ���Error case��Ŵ���ʲôλ�ã���֪ͨ����һЩʲôcase������ط��������ʲôλ�÷�����
			����Ŀû����ʾ��ֻ��ƾ�Լ����飬�ڿ϶�˼ά����ȷ�Ļ���ֻ�п�����һЩɵ�ƴ���������غ���Ĵ��󣬱������������

*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int MOD=1e9+7;
class Solution {
	public:
		int numDecodings(string s) {
			int len=s.length();
			int i;
//			vector<long long>dp(len+1,0);
			vector<int>dp(len+1,0);
			dp[0]=1;
			if(len)
				if(s[0]=='0')
					return 0;
				else
					dp[1]=s[0]=='*'?9:1;
			long long t;
			for(i=1; i<len; ++i) {
				if(s[i]=='0') {
					if(s[i-1]=='1'||s[i-1]=='2')
						t=dp[i-1];
					else if(s[i-1]=='*')
						t=dp[i-1]*2L;
					else
						return 0;
				} else if(s[i]=='*') {
//					t=dp[i]*(long long)9;	//��ȷ 
					t=dp[i]*9LL;			//��ȷ 
//					t=dp[i]*(long )9;		//���� 
//					t=dp[i]*9L;				//���� 
					if(s[i-1]=='*')
						t+=dp[i-1]*(long long)15;
					else if(s[i-1]=='1')
						t+=dp[i-1]*9L;
					else if(s[i-1]=='2')
						t+=dp[i-1]*6L;
				} else {
					t=dp[i];
					if(s[i-1]=='*')
						t+=(s[i]<='6'? 2L*dp[i-1] : dp[i-1]);
					else if(s.substr(i-1,2)>="10"&&s.substr(i-1,2)<="26")
						t+=dp[i-1];
				}
				dp[i+1]=t%MOD;
			}
			return dp[len];
		}
};

void testFun() {
	cout<<"sizeof (long		) = "<<sizeof(long		)<<endl;	//4
	cout<<"sizeof (long long) = "<<sizeof(long long	)<<endl;	//8
	cout<<"sizeof (0L		) = "<<sizeof(0L		)<<endl;	//4
	cout<<"sizeof (0LL		) = "<<sizeof(0LL		)<<endl;	//8
}

int main() {
	Solution s;
	string test="**********1111111111";
	string test1="*1111111111";
	string test2="111";

	cout<<s.numDecodings(test)<<endl;

	testFun();
	return 0;
}
