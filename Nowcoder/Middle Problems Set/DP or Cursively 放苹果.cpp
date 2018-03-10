/*
	这道题目本身较简单，最简单的方式是递归解法，不过正确思考出来需要逻辑缜密，分类周全。
	这道题目是一道整数剖分的题目，在组合数学和算法中都是老题。
	在此用动态规划完成。
	dp[m][n][k]表示m个水果放在n个盘子，每个盘子中水果数<=k; 
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
	解法二 
*/ 
int dp(int m, int n)
{
	// 递归出口：有0个苹果 || 只有1个盘子
	if (m == 0 || n == 1)
		return 1;
	if (n>m) // 盘子比较多，肯定有空盘子，去掉必空的盘子
		return dp(m, m);
	else // 苹果比较多：
		// 1：至少有一个空盘子，拿掉这个空盘子
		// 2：每个盘子都有苹果，各拿掉一个苹果（极限是最少的有1个苹果）
		return dp(m, n - 1) + dp(m - n, n);
}
