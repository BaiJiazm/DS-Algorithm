#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

vector<int>nums;
vector<vector<int>>over;

int solve(int begin, int end) {
	if(over[begin][end]!=INF) {
		return over[begin][end];
	}
	if(begin==end) {
		return over[begin][end]=nums[begin];
	}
	int t1=nums[begin]-solve(begin+1, end);
	int t2=nums[end]-solve(begin, end-1);
	return over[begin][end]=max(t1, t2);
}

int main() {
	int n;
	int i, t;
	scanf("%d", &n);
	nums=vector<int>(n, 0);
	over=vector<vector<int>>(n, vector<int>(n, INF));
	for (i=0; i<n; ++i) {
		scanf("%d", &t);
		nums[i]=t;
	}
	int ret=solve(0, n-1);
	cout<<(ret>0?1:ret<0?2:0)<<endl;
	return 0;
}
