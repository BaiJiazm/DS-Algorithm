/*
	哎哟，就差一分钟， 在最后6分钟前写好了后面的代码，虽然算法完全正确，
	但是Rum Time Error!, 我估计是开了一个大数组，后面又用到了一个大数组，可能爆内存，
	修改后再次提交，结果正确，可差了一分钟！结束了。 
	
	这道题目其实就是一个01背包问题。 好久没写代码了，速度有点慢啊。Duang！ 
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int val;
	int cost;
	node(int v, int t) {
		val=v;
		cost=t;
	}
};

int main() {
	int N,M;
	int i,j;
	int v;
	cin>>N>>M;
	vector<int>nums;
	for(i=0; i<N; ++i) {
		cin>>v;
		nums.push_back(v);
	}
	vector<node>n;
	
	sort(nums.begin(), nums.end());
	nums.push_back(0);
	int cnt;
	for(i=0; i<nums.size();++i)	{
		if(i==0||nums[i]!=nums[i-1]){
			if(i!=0)
				n.push_back(node(nums[i-1], cnt*nums[i-1]));
			cnt=1;
		}
		else 
			++cnt;
	}

	vector<vector<int>>dp(M+1, vector<int>(n.size()+1,0));
	for (j=1; j<=n.size(); ++j) {
		for (i=1; i<=M; ++i) {
			dp[i][j]=dp[i][j-1];
			if(j==1||n[j-1].val-n[j-2].val>1)
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]+n[j-1].cost);
			if(j-2>=0)
				dp[i][j]=max(dp[i][j], dp[i-1][j-2]+n[j-1].cost);
		}
	}

	cout<<dp[M][n.size()]<<endl;
	return 0;
}


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int val;
	int cost;
	node(int v, int t) {
		val=v;
		cost=t;
	}
};

//一般acm最多只能开一个大数组，且最好是全局变量，否则爆内存。 
#define MAX_VALUE 100005
int nums[MAX_VALUE]= {0};

int main() {
	int N,M;
	int i,j;
	int v;
	cin>>N>>M;
	for(i=0; i<N; ++i) {
		cin>>v;
		++nums[v];
	}
	vector<node>n;

	for(i=1; i<=MAX_VALUE; ++i)
		if(nums[i])
			n.push_back(node(i, i*nums[i]));

	vector<vector<int>>dp(M+1, vector<int>(n.size()+1,0));
	for (j=1; j<=n.size(); ++j) {
		for (i=1; i<=M; ++i) {
			dp[i][j]=dp[i][j-1];
			if(j==1||n[j-1].val-n[j-2].val>1)
				dp[i][j]=max(dp[i][j], dp[i-1][j-1]+n[j-1].cost);
			if(j-2>=0)
				dp[i][j]=max(dp[i][j], dp[i-1][j-2]+n[j-1].cost);
		}
	}

	cout<<dp[M][n.size()]<<endl;
	return 0;
}
