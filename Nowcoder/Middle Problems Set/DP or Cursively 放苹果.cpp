/*
	�����Ŀ����ϼ򵥣���򵥵ķ�ʽ�ǵݹ�ⷨ��������ȷ˼��������Ҫ�߼����ܣ�������ȫ��
	�����Ŀ��һ�������ʷֵ���Ŀ���������ѧ���㷨�ж������⡣
	�ڴ��ö�̬�滮��ɡ�
	dp[m][n][k]��ʾm��ˮ������n�����ӣ�ÿ��������ˮ����<=k; 
*/
#include<iostream>
#include<cstring>
using namespace std; 
#define NMAX 25
#define MMAX 25

int dp[MMAX][MMAX][NMAX];

int main(){
	int M,N;
	int m,n,k,i;
	while(cin>>M>>N){
		memset(dp, 0, sizeof(dp));
		for(m=0;m<=M;++m)
			for(k=0;k<=M;++k)
				dp[m][k][1]=(m<=k);
		for(n=2;n<=N;++n){
			for(m=0;m<=M;++m){
				for(k=0;k<=m;++k){
					for(i=0;i<=k;++i){
						dp[m][k][n]+=dp[m-i][min(k, i)][n-1];
					}
				}
				for(;k<=M;++k)
					dp[m][k][n]=dp[m][k-1][n];
			}
		}
		cout<<dp[M][M][N]<<endl;
	}
	return 0;
}

/*
	�ⷨ�� 
*/ 
int dp(int m, int n)
{
	// �ݹ���ڣ���0��ƻ�� || ֻ��1������
	if (m == 0 || n == 1)
		return 1;
	if (n>m) // ���ӱȽ϶࣬�϶��п����ӣ�ȥ���ؿյ�����
		return dp(m, m);
	else // ƻ���Ƚ϶ࣺ
		// 1��������һ�������ӣ��õ����������
		// 2��ÿ�����Ӷ���ƻ�������õ�һ��ƻ�������������ٵ���1��ƻ����
		return dp(m, n - 1) + dp(m - n, n);
}
